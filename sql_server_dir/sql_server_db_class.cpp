/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_dir/utils_include.h"
#include "../utils_dir/list_mgr_dir/list_entry_class.h"
#include "sql_server_db_class.h"

SqlServerDBClass::SqlServerDBClass(const char *db_name_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "SqlServerDBClass", "init");

}

SqlServerDBClass::~SqlServerDBClass() {
}

int SqlServerDBClass::dBId() {
    return this->listEntry_->id();
}

char *SqlServerDBClass::dBIdStr() {
    return this->listEntry_->idStr();
}

void SqlServerDBClass::bindListEntry(ListEntryClass *list_entry_object_val, const char *who_val) {
    this->listEntry_ = list_entry_object_val;
}

void SqlServerDBClass::unBindListEntry(const char *who_val) {
    this->listEntry_ = NULL;
}

void SqlServerDBClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void SqlServerDBClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void SqlServerDBClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void SqlServerDBClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
