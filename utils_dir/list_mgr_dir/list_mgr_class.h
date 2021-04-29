/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef LIST_MGR_CLASS_H
#define LIST_MGR_CLASS_H

#include <pthread.h>

class ListEntryClass;
class ListEntryInt;

class ListMgrClass {
public:
    ListMgrClass(int id_size_val, int array_size_val, const char *caller_name_val, int first_global_id_val);
    ~ListMgrClass();
    ListEntryClass *mallocEntry(void *entity_int_val);
    void freeEntry(ListEntryClass *entry_val);
    void flushEntry();
    ListEntryClass *getEntryByIdStr(const char *id_str_val);

private:
    bool abendListMgrClassIsOn;
    int idSize_;
    const char *callerName_;
    int globalId_;
    int MaxIdIndexTableIndex_;
    int maxIndex_;
    int maxGlobalId_;
    int entryCount_;
    ListEntryClass **oldEntryArray_;//needed for postponing garbage collection
    ListEntryClass **entryArray_;
    int arraySize_;
    pthread_mutex_t listMgrMutex_;

    int entryCount() { return this->entryCount_; }
    int idSize() { return this->idSize_; }
    int maxIndex() { return this->maxIndex_; }
    ListEntryClass **entryArray() { return this->entryArray_; }
    int allocId();
    ListEntryClass *mallocEntry_();
	void freeEntry_(ListEntryClass *entry_val);
    void flushEntry_();
    ListEntryClass *getEntryByIdStr_(int id_val, int index_val);
    void abendListMgr(const char *msg_val);
    void abendListMgr_(const char *msg_val);

    const char *objectName() { return "ListMgrClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
