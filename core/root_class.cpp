/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../utils/abend/abend_class.h"
#include "../utils/queue/list_queue_class.h"
#include "../utils/queue/queue_entry_class.h"
#include "root_class.h"
#include "raw_api_class.h"

RootClass::RootClass() {
	this->debug(true, "RootClass", "init");
	
	this->rawApiObject_ = new RawApiClass(this);
	this->utilsObject_ = new UtilsClass();
	ListQueueClass *q = new ListQueueClass(true, 0);
	q->enqueue((void *) "hello");
	q->enqueue((void *) "test queue");
	char *s = (char *) q->dequeue();
	this->log("RootClass", s);
	s = (char *) q->dequeue();
	this->log("RootClass", s);
}
RootClass::~RootClass() {
}

void RootClass::logIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sLog(s0, s1);
	}
}

void RootClass::abendIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sAbend(s0, s1);
	}
}
