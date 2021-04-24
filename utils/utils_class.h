/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef UTILS_CLASS_H
#define UTILS_CLASS_H

#include "abend/abend_class.h"

class UtilsClass {
public:
	UtilsClass();
	~UtilsClass();

	AbendClass* abendObject() { return this->abendObject_; }

private:
	AbendClass* abendObject_;
};

#endif
