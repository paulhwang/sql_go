/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../utils/utils_class.h"
#include "test_class.h"
#include "../core/raw_api_class.h"

TestClass::TestClass(RootClass *root_class_val) {
	this->rootClass_ = root_class_val;

	this->debug(true, "TestClass", "init");
}

TestClass::~TestClass() {
}

void TestClass::doTest() {
	this->debug(true, "doTest", "init");

	this->rootClass_->rawApiObject()->sqlite3Open("go_users", &this->userSqlite3_);

}

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


