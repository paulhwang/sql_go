/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef LIST_QUEUE_CLASS_H
#define LIST_QUEUE_CLASS_H

class ListQueueClass {
public:
	ListQueueClass();
	~ListQueueClass();

private:

	const char *objectName() { return "ListQueueClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1); }
    void abend(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1); }
    bool debugSwitchOn_ = true;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
