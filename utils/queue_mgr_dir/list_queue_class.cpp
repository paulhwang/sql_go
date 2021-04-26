/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <string.h>
#include <stdlib.h>
#include "../phwang.h"
#include "../abend_dir/abend_class.h"
#include "list_queue_class.h"
#include "queue_entry_class.h"

#define MAX_PENDING_THREAD_COUNT 5;
#define DEFAULT_MAX_QUEUE_LENGTH 1000;

ListQueueClass::ListQueueClass(bool do_suspend_val, int max_length_val) {
	this->debug(true, "ListQueueClass", "init");
    memset(this, 0, sizeof (*this));

    this->maxLength_ = max_length_val;
    this->abendQueueIsOn_ = true;
    this->maxPendingThreadCount_ = MAX_PENDING_THREAD_COUNT;

    //this->pendingThreadArray_ = new Thread[this->maxPendingThreadCount_];

    if (pthread_mutex_init(&this->queueMutex_, NULL) != 0) {
        this->abend("QueueClass", "pthread_mutex_init for queueMutex_ fail");
    }

    if (pthread_mutex_init(&this->pendingThreadMutex_, NULL) != 0) {
        this->abend("QueueClass", "pthread_mutex_init for pendingThreadMutex_fail");
    }

    if (this->maxLength_ == 0) {
        this->maxLength_ = DEFAULT_MAX_QUEUE_LENGTH;
    }
}

ListQueueClass::~ListQueueClass() {
}


void ListQueueClass::enqueue(void *data_val) {
    this->debug(false, "enqueue", (char *) data_val);

    QueueEntryClass *entry = new QueueEntryClass();
    entry->data = data_val;
        
    this->abendQueue("enqueue begin");
    pthread_mutex_lock(&this->queueMutex_);
    this->enqueue_(entry);
    pthread_mutex_unlock(&this->queueMutex_);
        
    this->interruptPendingThread();
    this->abendQueue("enqueue end");
}
    
void ListQueueClass::enqueue_(QueueEntryClass *entry_val) {
    if (this->head_ == 0) {
    	entry_val->next = 0;
     	entry_val->prev = 0;
        this->head_ = entry_val;
        this->tail_ = entry_val;
        this->length_ = 1;
    }
    else {
     	entry_val->next = 0;
       	entry_val->prev = this->tail_;
        this->tail_->next = entry_val;
        this->tail_ = entry_val;
        this->length_++;
    }
}

void *ListQueueClass::dequeue() {
    QueueEntryClass *entry;

    this->abendQueue("dequeue start");
    pthread_mutex_lock(&this->queueMutex_);
    entry = this->dequeue_();
    pthread_mutex_unlock(&this->queueMutex_);
    this->abendQueue("dequeue end");
        
    if (entry == 0) {
        return 0;
    }
    else {
        void *data = entry->data;
        delete entry;

        this->debug(false, "dequeue", (char *)data);
        return data;
    }
}

QueueEntryClass *ListQueueClass::dequeue_() {
    QueueEntryClass *entry;

    if (this->length_ == 0) {
        return 0;
    }

    if (this->length_ == 1) {
        entry = this->head_;
        this->head_ = this->tail_ = 0;
        this->length_ = 0;
        return entry;
    }

    entry = this->head_;
    this->head_ = this->head_->next;
    this->head_->prev = 0;
    this->length_--;

    return entry;
}

void ListQueueClass::flush() {
    this->abendQueue("flush start");
    pthread_mutex_lock(&this->queueMutex_);
    this->flush_();
    pthread_mutex_unlock(&this->queueMutex_);
    this->abendQueue("flush end");
}

void ListQueueClass::flush_() {
    QueueEntryClass *entry, *entry_next;

    entry = this->head_;
    while (entry != 0) {
        entry_next = entry->next;
        delete entry;
        this->length_--;
        entry = entry_next;
    }
    this->head_ = this->tail_ = 0;

    if (this->length_ != 0) {
        this->abend("flush_", "length is not 0");
    }
}

/*
void ListQueueClass::setPendingThread(Thread *thread_val) {
    pthread_mutex_lock(&this->pendingThreadMutex_);
    this_setPendingThread_(thread_val);
    pthread_mutex_unlock(&this->pendingThreadMutex_);
}

void ListQueueClass::setPendingThread_(Thread *thread_val) {
    for (int i = 0; i < this->maxPendingThreadCount_; i++) {
        if (this->pendingThreadArray_[i] == null) {
            this->pendingThreadArray_[i] = thread_val;
            return;
        }
    }
}
*/

void ListQueueClass::interruptPendingThread() {
    pthread_mutex_lock(&this->pendingThreadMutex_);
    this->interruptPendingThread_();
    pthread_mutex_unlock(&this->pendingThreadMutex_);
}
    
void ListQueueClass::interruptPendingThread_() {
    for (int i = 0; i < this->maxPendingThreadCount_; i++) {
    //    if (this.pendingThreadArray_[i] != null) {
    //        pendingThreadArray_[i].interrupt();
    //        this.pendingThreadArray_[i] = null;
            return;
    //    }
    }
}

void ListQueueClass::abendQueue(const char *msg_val) {
    if (!this->abendQueueIsOn_) {
        return;
    }
        
    pthread_mutex_lock(&this->queueMutex_);
    this->abendQueue_(msg_val);
    pthread_mutex_unlock(&this->queueMutex_);
}

void ListQueueClass::abendQueue_(const char *msg_val) {
    QueueEntryClass *entry;
    int length;

    if (this->length_ == 0) {
        if ((this->head_ != 0) || (this->tail_ != 0)) {
            this->abend("abendQueue_", msg_val /*+ " length_ == 0"*/);
        }
        return;
    }

    length = 0;
    entry = this->head_;
    while (entry != 0) {
        length++;
        entry = entry->next;
    }

    if (length != this->length_) {
        this->abend("abendQueue_", msg_val /*+ " from head: bad length"*/);
    }

    length = 0;
    entry = this->tail_;
    while (entry != 0) {
        length++;
        entry = entry->prev;
    }
    if (length != this->length_) {
       this->abend("abendQueue_", msg_val /*+ " from tail: bad length"*/);
    }
}

void ListQueueClass::logIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sLog(s0, s1);
	}
}

void ListQueueClass::abendIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sAbend(s0, s1);
	}
}
