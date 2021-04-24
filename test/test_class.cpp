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

TestClass::TestClass(RootClass *root_class_val) {
	printf("TestClass\n");
	this->rootClass_ = root_class_val;
	this->abendObject()->log("this","case");
}

TestClass::~TestClass() {
}

void TestClass::doTest() {
	printf("doTest\n");

	this->rootClass_->rawApiObject()->sqlite3Open("go_users", &this->userSqlite3_);

}

