/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "abend_class.h"

AbendClass::AbendClass() {
	printf("AbendClass\n");
}

AbendClass::~AbendClass() {
}

void AbendClass::log(const char* s0, const char* s1) {
	printf("%s %s\n", s0, s1);
    if (logStopped_) {
    	return;
    }
	//abendInt_.log(s0 + " " + s1);
}

