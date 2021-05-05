/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef SQL_SERVER_DB_MGR_CLASS_H
#define SQL_SERVER_DB_MGR_CLASS_H

class SqlServerRootClass;
class SqlServerDBClass;
class ListMgrClass;

#define SQL_DB_ID_SIZE_  4
#define SQL_DB_ID_SIZE  (SQL_DB_ID_SIZE_ * 2 + 2)
#define FIRST_DB_ID 8000
#define DB_LIST_MGR_ARRAY_SIZE 128

class SqlServerDBMgrClass {
public:
    SqlServerDBMgrClass(SqlServerRootClass *root_object_val);
    ~SqlServerDBMgrClass();

    SqlServerDBClass *mallocDB(const char *db_name_val);
    void freeDB(SqlServerDBClass *db_val);
    SqlServerDBClass *getDBByIdStr(const char *db_id_str_val);

private:
    SqlServerRootClass *rootObject_;
    ListMgrClass *listMgrObject_;

    const char *objectName() { return "SqlServerDBMgrClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
