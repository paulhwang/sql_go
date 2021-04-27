/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include "../utils_include.h"
#include "encoders_class.h"

EncodersClass::EncodersClass() {
}

EncodersClass::~EncodersClass() {
}

char *EncodersClass::iEncodeRaw(int number_val, int size_val) {
	return 0;
}

char *EncodersClass::iEncodeLen(int number_val, int size_val) {
    char *str = iEncodeRaw(number_val, size_val);
    return sEncode2(str);
}

int EncodersClass::iDecodeRaw(char *str_val) {
    int str_len = strlen(str_val);
    int val = 0;

    for (int i = 0; i < str_len; i++) {
        val += str_val[i] - '0';
        if (i < str_len - 1) {
            val *= 10;
        }
    }
    return val;
}

int EncodersClass::iDecodeLen(char *str_val) {
    char *str = sDecode2(str_val);
    return iDecodeRaw(str);
}

char *EncodersClass::sEncode(char *str_val, int size_val) {
	return 0;
}

char *EncodersClass::sDecode(char *str_val, int size_val) {
    //int len = Encoders.iDecodeRaw(str_val.substring(0, size_val));
    //return str_val.substring(size_val, size_val + len);
    return 0;
}

char *EncodersClass::sDecode_(char *str_val, int size_val) {
    //return str_val.substring(size_val + Encoders.iDecodeRaw(str_val.substring(0, size_val)));
    return 0;
}

char *EncodersClass::sSubstring(char *str_val, int size_val) {
	return 0;
    //int len = Encoders.iDecodeRaw(str_val.substring(0, size_val));
    //return str_val.substring(0, size_val + len);
}

char *EncodersClass::sSubstring_(char *str_val, int size_val) {
	return 0;
    //return str_val.substring(size_val + Encoders.iDecodeRaw(str_val.substring(0, size_val)));
}

void EncodersClass::subString(const char *from_str_val, char *to_str_val, int from_val, int to_val) {
    for (int i = from_val; i < to_val; i++) {
        to_str_val[i - from_val] = from_str_val[i];
    }
    to_str_val[to_val -from_val] = 0;
}
