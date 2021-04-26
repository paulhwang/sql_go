/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include "../sqlite_dir/sqlite3.h"
#include "../core/root_class.h"

class TestClass {
public:
	TestClass(RootClass *);
	~TestClass();
	void doTest();
	sqlite3 *userSqlite3() { return this->userSqlite3_; }
	UtilsClass *utilsObject() { return this->rootClass_->utilsObject(); }
	AbendClass* abendObject();

private:
	RootClass *rootClass_;
	sqlite3 *userSqlite3_;

	const char *objectName() { return "TestClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_ = true;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
