/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "binder_class.h"

BinderClass::BinderClass() {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "BinderClass", "init");
}

BinderClass::~BinderClass() {
}

void BinderClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void BinderClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void BinderClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void BinderClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
