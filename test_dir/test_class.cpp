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
#include "../sql_server_dir/sql_server_raw_api_class.h"
#include "test_class.h"

TestClass::TestClass(SqlServerRootClass *root_class_val) {
	this->rootClass_ = root_class_val;

	this->debug(true, "TestClass", "init");
}

TestClass::~TestClass() {
}

void TestClass::doTest() {
	this->debug(true, "doTest", "init");

	this->rootClass_->rawApiObject()->sqlite3Open("db_dir/go_users", &this->userSqlite3_);

}

AbendClass *TestClass::abendObject() { return this->utilsObject()->abendObject(); }
void TestClass::log(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1); }
void TestClass::abend(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1); }
void TestClass::logIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sLog(s0, s1);
	}
}

void TestClass::abendIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sAbend(s0, s1);
	}
}


