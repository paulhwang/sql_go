/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "abend_class.h"

bool AbendClass::sLogStopped_;

AbendClass::AbendClass() {
	printf("AbendClass\n");
	AbendClass::sLogStopped_ = false;
}

AbendClass::~AbendClass() {
}

void AbendClass::log(const char* s0, const char* s1) {
	printf("%s %s\n", s0, s1);
    if (AbendClass::sLogStopped_) {
    	return;
    }
	//abendInt_.log(s0 + " " + s1);
}

void AbendClass::sLog(const char* s0, const char* s1) {
	printf("%s %s\n", s0, s1);
    if (AbendClass::sLogStopped_) {
    	return;
    }
	//abendInt_.log(s0 + " " + s1);
}


void AbendClass::abend(const char* s0, const char* s1) {
    if (AbendClass::sLogStopped_) {
    	return;
    }
    AbendClass::sLogStopped_ = true;

    printf("***ABEND*** %s %s\n", s0, s1);
    int *junk = 0;
    *junk = 0;
}

void AbendClass::sAbend(const char* s0, const char* s1) {
    if (AbendClass::sLogStopped_) {
    	return;
    }
    AbendClass::sLogStopped_ = true;

    printf("***ABEND*** %s %s\n", s0, s1);
    int *junk = 0;
    *junk = 0;
}
