/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef THREAD_ENTITY_CLASS_H
#define THREAD_ENTITY_CLASS_H

class ThreadEntityClass {
public:
	ThreadEntityClass();
	~ThreadEntityClass();

private:

	const char *objectName() { return "ThreadEntityClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_ = true;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
