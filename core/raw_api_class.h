/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef RAW_API_CLASS_H
#define RAW_API_CLASS_H

#include "../sqlite/sqlite3.h"

class RootClass;

class RawApiClass {
public:
	RawApiClass(RootClass *root_object_val);
	~RawApiClass();

	int sqlite3Open(
		const char *filename,   /* Database filename (UTF-8) */
		sqlite3 **ppDb          /* OUT: SQLite db handle */
	);

	int sqlite3Prepare(
		sqlite3 *db,            /* Database handle */
  		const char *zSql,       /* SQL statement, UTF-8 encoded */
  		int nByte,              /* Maximum length of zSql in bytes. */
  		sqlite3_stmt **ppStmt,  /* OUT: Statement handle */
  		const char **pzTail     /* OUT: Pointer to unused portion of zSql */
	);

	int sqlite3BindInt(sqlite3_stmt*, int, int);
	int sqlite3BindNull(sqlite3_stmt*, int);
	int sqlite3BindText(sqlite3_stmt*, int, const char*, int, void(*)(void*));
	int sqlite3Step(sqlite3_stmt*);
	int sqlite3ColumnInt(sqlite3_stmt*, int iCol);
	const unsigned char *sqlite3ColumnText(sqlite3_stmt*, int iCol);
	int sqlite3Finalize(sqlite3_stmt *pStmt);
	int sqlite3Close(sqlite3*);
	
	int sqlite3Exec(
		sqlite3*,                                  /* An open database */
		const char *sql,                           /* SQL to be evaluated */
		int (*callback)(void*,int,char**,char**),  /* Callback function */
		void *,                                    /* 1st argument to callback */
		char **errmsg                              /* Error msg written here */
		);

private:
	const char *objectName() { return "RawApiClass"; }

	RootClass *rootObject_;
	RootClass *rootObject() { return this->rootObject_; }

    void debug(bool on_off_val, char *s0, char *s1);
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
};

#endif
