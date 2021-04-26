/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef THREAD_MGR_CLASS_H
#define THREAD_MGR_CLASS_H

class ThreadEntityClass;

class ThreadMgrClass {
public:
	ThreadMgrClass();
	~ThreadMgrClass();

	ThreadEntityClass *createThreadObject(char *thread_name_val, void *(*start_routine_val)(void *));

private:
	void insertToThreadList(ThreadEntityClass *thread_object_val);

	const char *objectName() { return "ThreadMgrClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
