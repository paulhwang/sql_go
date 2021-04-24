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
	UtilsClass *utilsObject() { return this->utilsObject_; }
	AbendClass* abendObject() { return this->utilsObject()->abendObject(); }

private:
	RawApiClass *rawApiObject_;
	UtilsClass *utilsObject_;
};

#endif
