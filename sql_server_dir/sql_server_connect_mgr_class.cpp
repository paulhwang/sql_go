/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_dir/utils_include.h"
#include "../utils_dir/list_mgr_dir/list_mgr_class.h"
#include "../utils_dir/list_mgr_dir/list_entry_class.h"
#include "sql_server_connect_mgr_class.h"
#include "sql_server_connect_class.h"

SqlServerConnectMgrClass::SqlServerConnectMgrClass(SqlServerRootClass *root_object_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "SqlServerConnectMgrClass", "init");

    this->rootObject_ = root_object_val;
    this->listMgrObject_ = new ListMgrClass(SQL_CONNECT_ID_SIZE_, CONNECT_LIST_MGR_ARRAY_SIZE, this->objectName(), FIRST_CONNECT_ID);
}

SqlServerConnectMgrClass::~SqlServerConnectMgrClass() {
    free(this->listMgrObject_);
}

SqlServerConnectClass *SqlServerConnectMgrClass::mallocConnect(const char *connect_name_val) {
    SqlServerConnectClass *connect = new SqlServerConnectClass(connect_name_val);
    ListEntryClass *list_entry = this->listMgrObject_->mallocEntry(connect);
    connect->bindListEntry(list_entry, this->objectName());
    return connect;
}

void SqlServerConnectMgrClass::freeConnect(SqlServerConnectClass *connect_val) {
    ListEntryClass *list_entry = connect_val->listEntry();
    connect_val->unBindListEntry(this->objectName());
    this->listMgrObject_->freeEntry(list_entry);
}
    
SqlServerConnectClass *SqlServerConnectMgrClass::getConnectByIdStr(const char *connect_id_str_val) {
    ListEntryClass *list_entry = this->listMgrObject_->getEntryByIdStr(connect_id_str_val);
    if (list_entry == NULL) {
        return NULL;
    }
    return (SqlServerConnectClass *) list_entry->data();
}

void SqlServerConnectMgrClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void SqlServerConnectMgrClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void SqlServerConnectMgrClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void SqlServerConnectMgrClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
