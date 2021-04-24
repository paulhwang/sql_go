/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H

#include "raw_api_class.h"
#include "../utils/utils_class.h"

class RootClass {
public:
	RootClass();
	~RootClass();
	
	RawApiClass *rawApiObject() { return this->rawApiObject_; }
	UtilsClass *utilsClass() { return this->utilsClass_; }

private:
	RawApiClass *rawApiObject_;
	UtilsClass *utilsClass_;
};

#endif
