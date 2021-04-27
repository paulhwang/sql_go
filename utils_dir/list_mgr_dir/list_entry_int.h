/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef LIST_ENTRY_INT_H
#define LIST_ENTRY_INT_H

class ListEntryInt {
public:
    void *(*bindListEntry)(ListEntryClass *list_entry_val, const char *who_val);
    void *(*unBindListEntry)(const char *who_val);
};

#endif

