/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "root_class.h"
#include "raw_api_class.h"

RootClass::RootClass() {
	printf("RootClass\n");
	new RawApiClass();
}

RootClass::~RootClass() {
}