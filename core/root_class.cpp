/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../utils/abend/abend_class.h"
#include "root_class.h"
#include "raw_api_class.h"

RootClass::RootClass() {
	this->debug(true, "RootClass", "init");
	
	this->rawApiObject_ = new RawApiClass(this);
	this->utilsObject_ = new UtilsClass();
}

RootClass::~RootClass() {
}

void RootClass::logIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sLog(s0, s1);
	}
}

void RootClass::abendIt(const char *s0, const char *s1) {
	if (this->debugSwitchOn_) {
		AbendClass::sAbend(s0, s1);
	}
}
