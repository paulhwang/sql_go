/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../utils_dir/utils_include.h"
#include "../utils_dir/utils_class.h"
#include "../utils_dir/abend_dir/abend_class.h"
#include "../utils_dir/encoders_dir/encoders_class.h"
#include "../utils_dir/queue_mgr_dir/list_queue_class.h"
#include "../utils_dir/queue_mgr_dir/queue_entry_class.h"
#include "../utils_dir/list_mgr_dir/list_mgr_class.h"
#include "../utils_dir/thread_mgr_dir/thread_entity_class.h"
#include "../utils_dir/thread_mgr_dir/thread_mgr_class.h"
#include "sql_server_root_class.h"
#include "sql_server_raw_api_class.h"

void *func1(void *) {
	printf("in func1\n");
	return NULL;
}
void *func2(void *) {
	printf("in func2\n");
	return NULL;
}

SqlServerRootClass::SqlServerRootClass() {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "SqlServerRootClass", "init");
    
	this->threadMgrObject_ = new ThreadMgrClass();
	this->rawApiObject_ = new SqlServerRawApiClass(this);
	this->utilsObject_ = new UtilsClass();
	
	ListQueueClass *q = new ListQueueClass(true, 0);
	q->enqueue((void *) "hello");
	q->enqueue((void *) "test queue");
	char *s = (char *) q->dequeue();
	this->log("SqlServerRootClass", s);
	s = (char *) q->dequeue();
	this->log("SqlServerRootClass", s);

	new ListMgrClass(4, 10, "SqlServerRootClass", 7000);
	this->threadMgrObject_->createThreadObject("aaa", func1);
	this->threadMgrObject_->createThreadObject("SqlServerRootClass", func2);


	char buf[30];
	const char *ss = "0123456789A";
	EncodersClass::subString(ss, buf, 3, 6);
	printf("substr=%s\n", buf);
	ss = ss + 2;
	printf("ss=%s\n", ss);

	char * r5 = EncodersClass::iEncodeRaw5(123);
	printf("r5=%s\n", r5);
	char * l5 = EncodersClass::iEncodeLen(123456789, 10);
	printf("l5=%s\n", l5);
	
}

SqlServerRootClass::~SqlServerRootClass() {
}





void SqlServerRootClass::log(const char *s0, const char *s1) {
	char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void SqlServerRootClass::abend(const char *s0, const char *s1) {
	char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void SqlServerRootClass::logIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sLog(s0, s1);
	}
}

void SqlServerRootClass::abendIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sAbend(s0, s1);
	}
}
