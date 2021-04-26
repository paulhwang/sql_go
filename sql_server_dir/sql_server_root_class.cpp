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
#include "../utils_dir/queue_mgr_dir/list_queue_class.h"
#include "../utils_dir/queue_mgr_dir/queue_entry_class.h"
#include "sql_server_root_class.h"
#include "sql_server_raw_api_class.h"

SqlServerRootClass::SqlServerRootClass() {
	this->debug(true, "SqlServerRootClass", "init");
	
	this->rawApiObject_ = new SqlServerRawApiClass(this);
	this->utilsObject_ = new UtilsClass();
	
	ListQueueClass *q = new ListQueueClass(true, 0);
	q->enqueue((void *) "hello");
	q->enqueue((void *) "test queue");
	char *s = (char *) q->dequeue();
	this->log("SqlServerRootClass", s);
	s = (char *) q->dequeue();
	this->log("SqlServerRootClass", s);
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
