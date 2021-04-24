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
