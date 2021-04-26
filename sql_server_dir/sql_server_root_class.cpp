/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../utils_dir/utils_class.h"
#include "../utils_dir/abend_dir/abend_class.h"
#include "../utils_dir/queue_mgr_dir/list_queue_class.h"
#include "../utils_dir/queue_mgr_dir/queue_entry_class.h"
#include "sql_server_root_class.h"
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

AbendClass *RootClass::abendObject() { return this->utilsObject()->abendObject(); }
void RootClass::log(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1); }
void RootClass::abend(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1); }

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
