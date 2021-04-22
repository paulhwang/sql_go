/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../sqlite/sqlite3.h"
#include "raw_api_class.h"

RawApiClass::RawApiClass() {
	printf("RawApiClass\n");
}

RawApiClass::~RawApiClass() {
}

int RawApiClass::sqlite3Open(const char *filename, sqlite3 **ppDb) {
	return sqlite3_open(filename, ppDb);
}

int RawApiClass::sqlite3Prepare(sqlite3 *db, const char *zSql, int nByte, sqlite3_stmt **ppStmt, const char **pzTail) {
	return sqlite3_prepare(db, zSql, nByte, ppStmt, pzTail);
}

int RawApiClass::sqlite3BindInt(sqlite3_stmt* stmt_val, int int_val1, int int_val2) {
	return sqlite3_bind_int(stmt_val, int_val1, int_val2);
}

int RawApiClass::sqlite3BindNull(sqlite3_stmt* stmt_val, int int_val) {
	return sqlite3_bind_null(stmt_val, int_val);
}

int RawApiClass::sqlite3BindText(sqlite3_stmt* stmt_val, int int_val1, const char* str_val, int int_val2, void(*)(void*)) {
	return sqlite3_bind_text(stmt_val, int_val1, str_val, int_val2, SQLITE_TRANSIENT);
}

int RawApiClass::sqlite3Step(sqlite3_stmt* stmt_val) {
	return sqlite3_step(stmt_val);
}

int RawApiClass::sqlite3ColumnInt(sqlite3_stmt* stmt_val, int iCol) {
	return sqlite3ColumnInt(stmt_val, iCol);
}

const unsigned char *RawApiClass::sqlite3ColumnText(sqlite3_stmt* stmt_val, int iCol) {
	return sqlite3_column_text(stmt_val, iCol);
}


int RawApiClass::sqlite3Finalize(sqlite3_stmt *pStmt) {
	return sqlite3_finalize(pStmt);
}

int RawApiClass::sqlite3Close(sqlite3* sqlite3_val) {
	return sqlite3_close(sqlite3_val);
}

int RawApiClass::sqlite3Exec(sqlite3* sqlite3_val, const char *sql, int (*callback)(void*,int,char**,char**), void * val, char **errmsg) {
	return sqlite3_exec(sqlite3_val, sql, callback, val, errmsg);
}
