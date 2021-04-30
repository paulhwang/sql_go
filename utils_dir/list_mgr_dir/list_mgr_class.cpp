/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_include.h"
#include "list_mgr_class.h"
#include "list_entry_class.h"
#include "list_entry_int.h"

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

    this->entryArray_ = (ListEntryClass **) malloc(this->arraySize_ * sizeof(ListEntryClass *));
}

ListMgrClass::~ListMgrClass() {
    this->flushEntry();
    free(this->entryArray_);
}

int ListMgrClass::allocId() {
    if (this->globalId_ >= this->maxGlobalId_) {
        this->globalId_ = -1;
    }
    this->globalId_++;
    return this->globalId_;
}

ListEntryClass *ListMgrClass::mallocEntry(void *entity_int_val) {
    char debug_buf[128];

    this->debug(false, "mallocEntry", "start");
        
    this->abendListMgr("before mallocEntry");

    pthread_mutex_lock(&this->listMgrMutex_);
        
    ListEntryClass *entry = this->mallocEntry_();
        
    int id = this->allocId();
    this->entryCount_++;
    entry->setData(id, entity_int_val);
    //entity_int_val->bindListEntry(entry, this->callerName_);
        
    pthread_mutex_unlock(&this->listMgrMutex_);

    this->abendListMgr("after mallocEntry");
        
    if (this->entryCount_ > this->maxGlobalId_) {
        sprintf(debug_buf, "entryCount_=%i > maxGlobalId_=%i", this->entryCount_, this->maxGlobalId_);
        this->abend("mallocEntry", debug_buf);
    }
        
    if (entry->index() > this->maxGlobalId_) {
        sprintf(debug_buf, "index=%i > maxGlobalId_=%i", entry->index(), this->maxGlobalId_);
        this->abend("mallocEntry", debug_buf);
    }
      
    sprintf(debug_buf, "id=%i > index=%i", entry->id(), entry->index());
    this->debug(false, "mallocEntry", debug_buf);
    return entry;
}

ListEntryClass *ListMgrClass::mallocEntry_() {
    for (int i = 0; i < this->arraySize_; i++) {
        if (this->entryArray_[i] == NULL) {
            this->entryArray_[i] = new ListEntryClass(i, this->idSize());
            if (i > this->maxIndex_) {
                    this->maxIndex_ = i;
            }
            else {
                this->abend("mallocEntry_", "maxIndex");
            }
            return this->entryArray_[i];
        }
        else {
            if (this->entryArray_[i]->data() == NULL) {
                return this->entryArray_[i];
            }
        }
    }

    this->oldEntryArray_ = this->entryArray_;
    ListEntryClass **new_array = (ListEntryClass **) malloc(this->arraySize_ * 2 * sizeof(ListEntryClass *));
    for (int i = 0; i < this->arraySize_; i++) {
        new_array[i] = this->oldEntryArray_[i];
        //*** to remove the lock from reading array //this.entryArray_[i] = null;;
    }
    free(this->oldEntryArray_);
    this->entryArray_ = new_array;
    this->maxIndex_ = this->arraySize_;
    this->arraySize_ = this->arraySize_ * 2;
    this->entryArray_[this->maxIndex_] = new ListEntryClass(this->maxIndex_, this->idSize());
    return this->entryArray_[this->maxIndex_];
}

void ListMgrClass::freeEntry(ListEntryClass *entry_val) {
    this->abendListMgr("before freeEntry");
        
    pthread_mutex_lock(&this->listMgrMutex_);
    this->freeEntry_(entry_val);
    pthread_mutex_unlock(&this->listMgrMutex_);
        
    this->abendListMgr("after freeEntry");
}

void ListMgrClass::freeEntry_(ListEntryClass *entry_val) {
    //this->entryArray_[entry_val->index()]->data()->unBindListEntry(this->callerName_);
    if (this->entryArray_[entry_val->index()] != entry_val) {
        this->abend("freeEntry_", "not match");
    }
    this->entryArray_[entry_val->index()]->clearData();
    //this->entryArray_[entry_val->index()] = NULL;
    //free(entry_val);
    this->entryCount_--;
}

void ListMgrClass::flushEntry() {
    this->abendListMgr("before flushEntry");
        
    pthread_mutex_lock(&this->listMgrMutex_);
    this->flushEntry_();
    pthread_mutex_unlock(&this->listMgrMutex_);
        
    this->abendListMgr("after flushEntry");
}

void ListMgrClass::flushEntry_() {
    for (int i = 0; i <= this->maxIndex_; i++) {
        //this->entryArray_[i]->data()->unBindListEntry(this->callerName_);
        this->entryArray_[i]->clearData();
        free(this->entryArray_[i]);
        this->entryArray_[i] = NULL;
    }
    this->entryCount_ = 0;
}

ListEntryClass *ListMgrClass::getEntryByIdStr(const char *id_str_val) {
    char id_str[32];
    memcpy(id_str, id_str_val + 2, this->idSize_);
    id_str[idSize_] = 0;
    int id = EncodersClass::iDecodeRaw(id_str);
    //printf("getEntryByIdStr %s %s %d\n", id_str_val, id_str, id);

    char index_str[32];
    strcpy(index_str, id_str_val + 2 + idSize_);
    int index = EncodersClass::iDecodeRaw(index_str);
    //printf("getEntryByIdStr %s %s %d\n", id_str_val, index_str, index);

    //printf("getEntryByIdStr %s %d %d\n", id_str_val, id, index);

    ListEntryClass *entry;
    //this.theLock.lock();
    entry = this->getEntryByIdStr_(id, index);
    //this.theLock.unlock();
    return entry;
}
    
ListEntryClass *ListMgrClass::getEntryByIdStr_(int id_val, int index_val) {
    ListEntryClass *entry = this->entryArray_[index_val];
    if (entry == NULL) {
        this->abend("getEntryByIdStr_", "null entry");
        return NULL;
    }
        
    if (entry->data() == NULL) {
        this->abend("getEntryByIdStr_", "null data");
        return NULL;
    }
        
    if (entry->id() != id_val) {
        this->abend("getEntryByIdStr_", "id not match");
        return NULL;
    }
    return entry;
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
