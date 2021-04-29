/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef LIST_ENTRY_CLASS_H
#define LIST_ENTRY_CLASS_H

class ListEntryInt;

class ListEntryClass {
public:
    ListEntryClass(int index_val, int id_size_val);
    ~ListEntryClass();

    int index() { return this->index_; }
    int id() { return this->id_; }
    char *idStr() { return this->id_str_; }
    void *data() { return this->data_; }
    void setData(int id_val, void *data_val);
	void clearData();

private:
    int id_;
    char *id_str_;
    void *data_;
    int id_size_;
    int index_;
    char *indexStr_;

    const char *objectName() { return "ListEntryClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
