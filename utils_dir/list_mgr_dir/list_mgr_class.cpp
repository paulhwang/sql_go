/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */


#include "../utils_include.h"
#include "list_mgr_class.h"

ListMgrClass::ListMgrClass(int id_size_val, int array_size_val, const char *caller_name_val, int first_global_id_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "ListMgrClass", "init");

    this->abendListMgrClassIsOn = true;
    this->idSize_ = id_size_val;
    this->callerName_ = caller_name_val;
    this->globalId_ = first_global_id_val - 1;
    this->entryCount_ = 0;
    this->MaxIdIndexTableIndex_ = 0;
    this->maxIndex_ = -1;
    //this->lock_ = new ReentrantLock();
    this->arraySize_ = array_size_val;
        
    this->maxGlobalId_ = 1;
    for (int i = 0; i < this->idSize_; i++) {
        this->maxGlobalId_ *= 10;
    }
    this->maxGlobalId_ -= 1;
        
    //this->entryArray_ = new ListEntry[this->arraySize_];

}

ListMgrClass::~ListMgrClass() {

}

int ListMgrClass::allocId() {
    if (this->globalId_ >= this->maxGlobalId_) {
        this->globalId_ = -1;
    }
    this->globalId_++;
    return this->globalId_;
}


void ListMgrClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void ListMgrClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void ListMgrClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void ListMgrClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}
