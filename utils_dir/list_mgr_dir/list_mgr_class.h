/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef LIST_MGR_CLASS_H
#define LIST_MGR_CLASS_H

class ListMgrClass {
public:
	ListMgrClass(int id_size_val, int array_size_val, const char *caller_name_val, int first_global_id_val);
	~ListMgrClass();

private:
    bool abendListMgrClassIsOn;
    int idSize_;
    const char *callerName_;
    int globalId_;
    int MaxIdIndexTableIndex_;
    int maxIndex_;
    int maxGlobalId_;
    int entryCount_;
    //ListEntry[] oldEntryArray_;//needed for postponing garbage collection
    //ListEntry[] entryArray_;
    int arraySize_;
    //Lock lock_;

    int allocId();

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
