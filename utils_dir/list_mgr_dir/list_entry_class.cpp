/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_include.h"
#include "list_entry_class.h"

ListEntryClass::ListEntryClass(int index_val, int id_size_val) {
    memset(this, 0, sizeof (*this));
    this->debugSwitchOn_ = true;
    this->debug(true, "ListEntryClass", "init");
    
    this->index_ = index_val;
    this->id_size_ = id_size_val;
    this->indexStr_ = EncodersClass::iEncodeRaw(this->index_, this->id_size_);
}

ListEntryClass::~ListEntryClass() {
}

void ListEntryClass::setData(int id_val, ListEntryInt *data_val) {
    this->id_ = id_val;
    this->data_ = data_val;
    //StringBuilder id_str_buf = new StringBuilder(Encoders.iEncodeRaw(this.id_, this.id_size_));
    //id_str_buf.append(this.indexStr_);
    //this.id_str_ = Encoders.sEncode2(id_str_buf.toString());
}

void ListEntryClass::clearData() {
    this->data_ = NULL;
}

void ListEntryClass::log(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1);
}

void ListEntryClass::abend(const char *s0, const char *s1) {
    char buf[UTILS_DEFINE_ABEND_BUF_SIZE]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1);
}

void ListEntryClass::logIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sLog(s0, s1);
    }
}

void ListEntryClass::abendIt(const char *s0, const char *s1) {
    if (this->debugSwitchOn_) {
        AbendClass::sAbend(s0, s1);
    }
}


