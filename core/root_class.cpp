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
	this->debug(true, "RootClass", "init");
	
	this->rawApiObject_ = new RawApiClass();
	this->utilsObject_ = new UtilsClass();
}

RootClass::~RootClass() {
}
