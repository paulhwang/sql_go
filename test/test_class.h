/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include "../sqlite/sqlite3.h"
#include "../core/root_class.h"

class TestClass {
public:
	TestClass(RootClass *);
	~TestClass();
	void doTest();
	sqlite3 *userSqlite3() { return this->userSqlite3_; }
	UtilsClass *utilsObject() { return this->rootClass_->utilsObject(); }
	AbendClass* abendObject() { return this->utilsObject()->abendObject(); }

private:
	RootClass *rootClass_;
	sqlite3 *userSqlite3_;

};

#endif
