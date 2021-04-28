/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef SQL_SERVER_UPARSER_CLASS_H
#define SQL_SERVER_UPARSER_CLASS_H

class SqlServerRootClass;

class SqlServerUParserClass {
public:
    SqlServerUParserClass(SqlServerRootClass *root_object_val);
    ~SqlServerUParserClass();

private:
    SqlServerRootClass *rootObject_;

    const char *objectName() { return "SqlServerUParserClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
