/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_include.h"
#include "thread_mgr_class.h"
#include "thread_entity_class.h"

ThreadMgrClass::ThreadMgrClass() {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "ThreadMgrClass", "init");

}

ThreadMgrClass::~ThreadMgrClass() {

}

ThreadEntityClass *ThreadMgrClass::createThreadObject(char *thread_name_val, void *calling_object_val) {
    ThreadEntityClass *thread_object = new ThreadEntityClass(thread_name_val, calling_object_val);
    this->insertToThreadList(thread_object);
    return thread_object;
}
    
void ThreadMgrClass::insertToThreadList(ThreadEntityClass *thread_object_val) {
        
}

void ThreadMgrClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void ThreadMgrClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void ThreadMgrClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void ThreadMgrClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
