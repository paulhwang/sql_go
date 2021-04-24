/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "queue_entry_class.h"

QueueEntryClass::QueueEntryClass() {
	printf("QueueEntryClass\n");
}

QueueEntryClass::~QueueEntryClass() {
}

void QueueEntryClass::clear() {
   	this->next = 0;
   	this->prev = 0;
   	this->data = 0;
};
