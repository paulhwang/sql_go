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
#include "../utils_dir/list_mgr_dir/list_mgr_class.h"
#include "../utils_dir/list_mgr_dir/list_entry_class.h"
#include "../sql_server_dir/sql_server_raw_api_class.h"
#include "../sql_server_dir/sql_server_connect_mgr_class.h"
#include "../sql_server_dir/sql_server_connect_class.h"
#include "../sqlite_dir/sqlite3.h"
#include "test_class.h"

TestClass::TestClass(SqlServerRootClass *root_class_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "TestClass", "init");

    this->sqlServerRootObject_ = root_class_val;
}

TestClass::~TestClass() {
}

void TestClass::doTest() {
    this->debug(true, "doTest", "init");
    this->testConnect();
    this->testSqlite();
}

void TestClass::testConnect() {
    SqlServerConnectClass *connect = this->sqlServerRootObject_->connectMgrObject()->mallocConnect("test001");
    connect = this->sqlServerRootObject_->connectMgrObject()->mallocConnect("test002");
    connect = this->sqlServerRootObject_->connectMgrObject()->mallocConnect("test003");
    this->sqlServerRootObject_->connectMgrObject()->freeConnect(connect);
    connect = this->sqlServerRootObject_->connectMgrObject()->mallocConnect("test004");
    this->sqlServerRootObject_->connectMgrObject()->freeConnect(connect);
    connect = this->sqlServerRootObject_->connectMgrObject()->mallocConnect("test005");
    this->debug(true, "testConnect", connect->connectIdStr());
    SqlServerConnectClass *connect1 = this->sqlServerRootObject_->connectMgrObject()->getConnectByIdStr(connect->connectIdStr());
    this->debug(true, "testConnect1", connect1->connectIdStr());
    this->debug(true, "tetestConnect", "done");
}

void TestClass::testSqlite() {
    //this->sqlServerRootObject_->rawApiObject()->sqlite3Open("db_dir/go_users.db", &this->userSqlite3_);
    sqlite3 *s;
    int result = sqlite3_open("db_dir/test.db", &s);

}

void TestClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void TestClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
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
