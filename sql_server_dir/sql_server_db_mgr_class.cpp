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
#include "sql_server_db_mgr_class.h"
#include "sql_server_db_class.h"

SqlServerDBMgrClass::SqlServerDBMgrClass(SqlServerRootClass *root_object_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "SqlServerDBMgrClass", "init");

    this->rootObject_ = root_object_val;
    this->listMgrObject_ = new ListMgrClass(SQL_DB_ID_SIZE_, DB_LIST_MGR_ARRAY_SIZE, this->objectName(), FIRST_DB_ID);
}

SqlServerDBMgrClass::~SqlServerDBMgrClass() {
    free(this->listMgrObject_);
}

SqlServerDBClass *SqlServerDBMgrClass::mallocDB(const char *db_name_val) {
    SqlServerDBClass *db = new SqlServerDBClass(db_name_val);
    ListEntryClass *list_entry = this->listMgrObject_->mallocEntry(db);
    db->bindListEntry(list_entry, this->objectName());
    return db;
}

void SqlServerDBMgrClass::freeDB(SqlServerDBClass *connect_val) {
    ListEntryClass *list_entry = connect_val->listEntry();
    connect_val->unBindListEntry(this->objectName());
    this->listMgrObject_->freeEntry(list_entry);
}
    
SqlServerDBClass *SqlServerDBMgrClass::getDBByIdStr(const char *db_id_str_val) {
    ListEntryClass *list_entry = this->listMgrObject_->getEntryByIdStr(db_id_str_val);
    if (list_entry == NULL) {
        return NULL;
    }
    return (SqlServerDBClass *) list_entry->data();
}

void SqlServerDBMgrClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void SqlServerDBMgrClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void SqlServerDBMgrClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void SqlServerDBMgrClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
