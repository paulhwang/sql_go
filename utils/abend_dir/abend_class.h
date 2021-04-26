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

	void log(const char* s0, const char* s1);
	static void sLog(const char* s0, const char* s1);

    void abend(const char* s0, const char* s1);
    static void sAbend(const char* s0, const char* s1);

private:
	static bool sLogStopped_;
};

#endif
