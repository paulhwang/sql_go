/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H

//#include "./raw_api_class.h"
#include "../utils/utils_class.h"

class RawApiClass;

class RootClass {
public:
	RootClass();
	~RootClass();

	RawApiClass *rawApiObject() { return this->rawApiObject_; }
	UtilsClass *utilsObject() { return this->utilsObject_; }
	AbendClass* abendObject() { return this->utilsObject()->abendObject(); }

    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);

private:
	const char *objectName() { return "RootClass"; }
	RawApiClass *rawApiObject_;
	UtilsClass *utilsObject_;

    bool debugSwitchOn_ = true;
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1); }
    void abend(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1); }
};

#endif
