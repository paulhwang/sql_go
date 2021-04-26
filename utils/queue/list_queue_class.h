/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef LIST_QUEUE_CLASS_H
#define LIST_QUEUE_CLASS_H

#include <pthread.h>

class QueueEntryClass;

class ListQueueClass {
public:
	ListQueueClass(bool do_suspend_val, int max_length_val);
	~ListQueueClass();
    int length() { return this->length_; }
    void enqueue(void *data_val);
    void *dequeue();
    void flush();
    //void setPendingThread(Thread *thread_val);

private:
	int length_;
    QueueEntryClass *head_;
    QueueEntryClass *tail_;
    pthread_mutex_t queueMutex_;
    pthread_mutex_t pendingThreadMutex_;
    int maxLength_;
    int maxPendingThreadCount_;
    //Thread[] pendingThreadArray_;
    bool abendQueueIsOn_;
    
	void enqueue_(QueueEntryClass *entry_val);
	QueueEntryClass *dequeue_();
	void flush_();
    //void setPendingThread_(Thread *thread_val);
    void interruptPendingThread();
    void interruptPendingThread_();
    void abendQueue(const char *msg_val);
	void abendQueue_(const char *msg_val);

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
