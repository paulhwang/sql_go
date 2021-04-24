/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../abend/abend_class.h"
#include "list_queue_class.h"
#include "queue_entry_class.h"

ListQueueClass::ListQueueClass() {
	this->debug(true, "ListQueueClass", "init");
	this->length_ = 0;
	this->head_ = 0;
	this->tail_ = 0;
}

ListQueueClass::~ListQueueClass() {
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
