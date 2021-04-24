/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../abend/abend_class.h"
#include "list_queue_class.h"

ListQueueClass::ListQueueClass() {
	this->debug(true, "ListQueueClass", "init");
}

ListQueueClass::~ListQueueClass() {
}

void ListQueueClass::logIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sLog(s0, s1);
	}
}

void ListQueueClass::abendIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sAbend(s0, s1);
	}
}
