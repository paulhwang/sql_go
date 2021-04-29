/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef SQL_SERVER_CONNECT_CLASS_H
#define SQL_SERVER_CONNECT_CLASS_H

class SqlServerRootClass;
class ListMgrClass;
class ListEntryClass;

class SqlServerConnectClass {
public:
    SqlServerConnectClass(const char *connect_name_val);
    ~SqlServerConnectClass();

    int connectId();
    char *connectIdStr();
    ListEntryClass *listEntry() { return this->listEntry_; }
    void bindListEntry(ListEntryClass *list_entry_object_val, const char *who_val);
    void unBindListEntry(const char *who_val);

private:
    ListEntryClass *listEntry_;

    const char *objectName() { return "SqlServerConnectClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
