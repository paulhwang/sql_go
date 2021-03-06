/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_include.h"
#include "thread_entity_class.h"

ThreadEntityClass::ThreadEntityClass(const char *thread_name_val, void *(*start_routine_val)(void *)) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "ThreadEntityClass", thread_name_val);

    this->threadName_ = thread_name_val;
    pthread_create(&this->thread_, NULL, start_routine_val, NULL);

}

ThreadEntityClass::~ThreadEntityClass() {

}


void ThreadEntityClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void ThreadEntityClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void ThreadEntityClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void ThreadEntityClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
