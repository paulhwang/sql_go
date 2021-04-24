/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H

#include "./raw_api_class.h"
#include "../utils/utils_class.h"

class RootClass {
public:
	RootClass();
	~RootClass();

	RawApiClass *rawApiObject() { return this->rawApiObject_; }
	UtilsClass *utilsObject() { return this->utilsObject_; }
	AbendClass* abendObject() { return this->utilsObject()->abendObject(); }


private:
	const char *objectName() { return "RootClass"; }
	RawApiClass *rawApiObject_;
	UtilsClass *utilsObject_;

    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->logIt(buf, s1); }
    void abend(const char *s0, const char *s1) { char buf[1048]; sprintf(buf, "%s.%s()", this->objectName(), s0); this->abendIt(buf, s1); }
    bool debug_on = true;
protected:
    void logIt(const char *s0, const char *s1) { if (this->debug_on) AbendClass::sLog(s0, s1); }
    void abendIt(const char *s0, const char *s1) { if (this->debug_on) AbendClass::sAbend(s0, s1); }
};

#endif
