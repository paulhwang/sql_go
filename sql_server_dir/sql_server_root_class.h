/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef SQL_SERVER_ROOT_CLASS_H
#define SQL_SERVER_ROOT_CLASS_H

class UtilsClass;
class AbendClass;
class ThreadMgrClass;
class SqlServerRawApiClass;
class SqlServerUParserClass;
class SqlServerDBinderClass;
class SqlServerConnectMgrClass;

class SqlServerRootClass {
public:
    SqlServerRootClass();
    ~SqlServerRootClass();

    ThreadMgrClass *threadMgrObject_;
    SqlServerRawApiClass *rawApiObject() { return this->rawApiObject_; }
    UtilsClass *utilsObject() { return this->utilsObject_; }

private:
    SqlServerUParserClass *uParserObject_;
    SqlServerDBinderClass *dBinderObject_;
    SqlServerConnectMgrClass *connectMgrObject_;
    SqlServerRawApiClass *rawApiObject_;
    UtilsClass *utilsObject_;

    const char *objectName() { return "SqlServerRootClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
