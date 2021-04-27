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
    this->arraySize_ = array_size_val;
        
    this->maxGlobalId_ = 1;
    for (int i = 0; i < this->idSize_; i++) {
        this->maxGlobalId_ *= 10;
    }
    this->maxGlobalId_ -= 1;

    if (pthread_mutex_init(&this->listMgrMutex_, NULL) != 0) {
        this->abend("ListMgrClass", "pthread_mutex_init for listMgrMutex_ fail");
    }

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

ListEntryClass *ListMgrClass::mallocEntry(ListEntryInt *entity_int_val) {
    this->debug(false, "malloc", "start");
        
    this->abendListMgr("before malloc");

    pthread_mutex_lock(&this->listMgrMutex_);
        
    ListEntryClass *entry = this->mallocEntry_();
        
    int id = this->allocId();
    this->entryCount_++;
    //entry->setData(id, entity_int_val);
    //entity_int_val->bindListEntry(entry, this->callerName_);
        
    pthread_mutex_unlock(&this->listMgrMutex_);

    this->abendListMgr("after malloc");
        
    if (this->entryCount_ > this->maxGlobalId_) {
        //this->abend("malloc", "entryCount_=" + this->entryCount_ + " > maxGlobalId_=" + this->maxGlobalId_);
    }
        
    //if (entry->index() > this->maxGlobalId_) {
        //this->abend("malloc", "index=" + entry->index() + " > maxGlobalId_=" + this->maxGlobalId_);
    //}
      
    //this->debug(false, "malloc", "id=" + entry.id() + " index=" + entry->index());
    return entry;
}

ListEntryClass *ListMgrClass::mallocEntry_() {
    return 0;
}

void ListMgrClass::free(ListEntryClass *entry_val) {
    this->abendListMgr("before free");
        
    pthread_mutex_lock(&this->listMgrMutex_);
    this->free_(entry_val);
    pthread_mutex_unlock(&this->listMgrMutex_);
        
    this->abendListMgr("after free");
}

void ListMgrClass::free_(ListEntryClass *entry_val) {
    //this.entryArray_[entry_val.index()].data().unBindListEntry(this.callerName_);
    //this.entryArray_[entry_val.index()].clearData();
    this->entryCount_--;
}

void ListMgrClass::flush() {
    this->abendListMgr("before flush");
        
    pthread_mutex_lock(&this->listMgrMutex_);
    this->flush_();
    pthread_mutex_unlock(&this->listMgrMutex_);
        
    this->abendListMgr("after flush");
}

void ListMgrClass::flush_() {
    for (int i = 0; i <= this->maxIndex_; i++) {
        //this->entryArray_[i]->data().unBindListEntry(this->callerName_);
        //this->entryArray_[i]->clearData();
        //this->entryArray_[i] = null;
    }
    this->entryCount_ = 0;
}

void ListMgrClass::abendListMgr(const char *msg_val) {
    if (!this->abendListMgrClassIsOn)
        return;
        
    pthread_mutex_lock(&this->listMgrMutex_);
    this->abendListMgr_(msg_val);
    pthread_mutex_unlock(&this->listMgrMutex_);
}
    
void ListMgrClass::abendListMgr_(const char *msg_val) {
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
