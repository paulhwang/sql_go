/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H

class UtilsClass;
class AbendClass;
class RawApiClass;

class RootClass {
public:
	RootClass();
	~RootClass();

	RawApiClass *rawApiObject() { return this->rawApiObject_; }
	UtilsClass *utilsObject() { return this->utilsObject_; }
	AbendClass* abendObject();

private:
	RawApiClass *rawApiObject_;
	UtilsClass *utilsObject_;

	const char *objectName() { return "RootClass"; }
    void debug(bool on_off_val, const char *s0, const char *s1) { if (on_off_val) this->log(s0, s1); }
    void log(const char *s0, const char *s1);
    void abend(const char *s0, const char *s1);
    bool debugSwitchOn_ = true;
public:
    void logIt(const char *s0, const char *s1);
    void abendIt(const char *s0, const char *s1);
};

#endif
