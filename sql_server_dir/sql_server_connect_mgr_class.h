/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef SQL_SERVER_CONNECT_MGR_CLASS_H
#define SQL_SERVER_CONNECT_MGR_CLASS_H

class SqlServerRootClass;
class SqlServerConnectClass;
class ListMgrClass;

#define SQL_CONNECT_ID_SIZE_  4
#define SQL_CONNECT_ID_SIZE  (SQL_CONNECT_ID_SIZE_ * 2 + 2)
#define FIRST_CONNECT_ID 9000
#define CONNECT_LIST_MGR_ARRAY_SIZE 128

class SqlServerConnectMgrClass {
public:
    SqlServerConnectMgrClass(SqlServerRootClass *root_object_val);
    ~SqlServerConnectMgrClass();

    SqlServerConnectClass *mallocConnect(const char *connect_name_val);
    void freeConnect(SqlServerConnectClass *connect_val);
    SqlServerConnectClass *getConnectByIdStr(const char *connect_id_str_val);

private:
    SqlServerRootClass *rootObject_;
    ListMgrClass *listMgrObject_;

    const char *objectName() { return "SqlServerConnectMgrClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
