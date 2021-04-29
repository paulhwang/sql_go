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
#include "../sqlite_dir/sqlite3.h"
#include "sql_server_root_class.h"
#include "sql_server_raw_api_class.h"

SqlServerRawApiClass::SqlServerRawApiClass(SqlServerRootClass *root_object_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "SqlServerRawApiClass", "init");

    this->rootObject_ = root_object_val;
}

SqlServerRawApiClass::~SqlServerRawApiClass() {
}

int SqlServerRawApiClass::sqlite3Open(const char *filename, sqlite3 **ppDb) {
    this->debug(true, "sqlite3Open", filename);
	int result = sqlite3_open(filename, ppDb);
    this->debug(true, "sqlite3Open", "done");
    return result;
}

int SqlServerRawApiClass::sqlite3Prepare(sqlite3 *db, const char *zSql, int nByte, sqlite3_stmt **ppStmt, const char **pzTail) {
	return sqlite3_prepare_v2(db, zSql, nByte, ppStmt, pzTail);
}

int SqlServerRawApiClass::sqlite3BindInt(sqlite3_stmt* stmt_val, int int_val1, int int_val2) {
	return sqlite3_bind_int(stmt_val, int_val1, int_val2);
}

int SqlServerRawApiClass::sqlite3BindNull(sqlite3_stmt* stmt_val, int int_val) {
	return sqlite3_bind_null(stmt_val, int_val);
}

int SqlServerRawApiClass::sqlite3BindText(sqlite3_stmt* stmt_val, int int_val1, const char* str_val, int int_val2, void(*)(void*)) {
	return sqlite3_bind_text(stmt_val, int_val1, str_val, int_val2, SQLITE_TRANSIENT);
}

int SqlServerRawApiClass::sqlite3Step(sqlite3_stmt* stmt_val) {
	return sqlite3_step(stmt_val);
}

int SqlServerRawApiClass::sqlite3ColumnInt(sqlite3_stmt* stmt_val, int iCol) {
	return sqlite3ColumnInt(stmt_val, iCol);
}

const unsigned char *SqlServerRawApiClass::sqlite3ColumnText(sqlite3_stmt* stmt_val, int iCol) {
	return sqlite3_column_text(stmt_val, iCol);
}

int SqlServerRawApiClass::sqlite3Finalize(sqlite3_stmt *pStmt) {
	return sqlite3_finalize(pStmt);
}

int SqlServerRawApiClass::sqlite3Close(sqlite3* sqlite3_val) {
	return sqlite3_close(sqlite3_val);
}

int SqlServerRawApiClass::sqlite3Exec(sqlite3* sqlite3_val, const char *sql, int (*callback)(void*,int,char**,char**), void * val, char **errmsg) {
	return sqlite3_exec(sqlite3_val, sql, callback, val, errmsg);
}

void SqlServerRawApiClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void SqlServerRawApiClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void SqlServerRawApiClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void SqlServerRawApiClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}


