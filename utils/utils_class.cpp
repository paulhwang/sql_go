/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "utils_class.h"

UtilsClass::UtilsClass() {
	printf("UtilsClass\n");

	this->abendObject_ = new AbendClass();
}

UtilsClass::~UtilsClass() {
}

