/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef ABEND_CLASS_H
#define ABEND_CLASS_H

class AbendClass {
public:
	AbendClass();
	~AbendClass();

	static void log(char* s0, char* s1);

private:
	bool logStopped_ = false;
};

#endif
