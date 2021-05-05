/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_dir/utils_include.h"
#include "../utils_dir/list_mgr_dir/list_entry_class.h"
#include "sql_server_connect_class.h"

SqlServerConnectClass::SqlServerConnectClass(const char *connect_name_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "SqlServerConnectClass", "init");

}

SqlServerConnectClass::~SqlServerConnectClass() {
}

int SqlServerConnectClass::connectId() {
    return this->listEntry_->id();
}

char *SqlServerConnectClass::connectIdStr() {
    return this->listEntry_->idStr();
}

void SqlServerConnectClass::bindListEntry(ListEntryClass *list_entry_object_val, const char *who_val) {
    this->listEntry_ = list_entry_object_val;
}

void SqlServerConnectClass::unBindListEntry(const char *who_val) {
    this->listEntry_ = NULL;
}

void SqlServerConnectClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void SqlServerConnectClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void SqlServerConnectClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void SqlServerConnectClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
