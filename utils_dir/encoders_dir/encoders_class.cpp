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
    char *buf = (char *) malloc(size_val + 1);
    memset(buf, '0', size_val);
    buf[size_val] = 0;
    int number = number_val;
    for (int i = size_val - 1; i >= 0; i--) {
        buf[i] = number % 10 + 48;
        number /= 10;
        if (number == 0)
            break;
    }
    return buf;
}

char *EncodersClass::iEncodeLen(int number_val, int size_val) {
    char *buf = (char *) malloc(size_val + 2 + 1);
    buf[1] = size_val % 10 + '0';
    buf[0] = size_val / 10 + '0';

    memset(buf + 2, '0', size_val);
    buf[size_val + 2] = 0;
    int number = number_val;
    for (int i = size_val - 1; i >= 0; i--) {
        buf[i + 2] = number % 10 + '0';
        number /= 10;
        if (number == 0)
            break;
    }
    return buf;
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
    int len = (str_val[0] - '0') * 10 + str_val[1] - '0';
    char buf[32];
    memcpy(buf, str_val + 2, len + 1);
    return iDecodeRaw(buf);
}

char *EncodersClass::sEncode(const char *str_val, int size_val) {
    int str_len = strlen(str_val);
    char *buf = (char *) malloc(size_val + str_len + 1);
    char *s = iEncodeRaw(str_len, size_val);
    memcpy(buf, s, size_val);
    strcpy(buf + size_val, str_val);
    free(s);
	return buf;
}

char *EncodersClass::sDecode(char *str_val, int size_val) {
    char length_buf[8];
    memcpy(length_buf, str_val, size_val);
    length_buf[size_val] = 0;
    int len = iDecodeRaw(length_buf);

    char *buf = (char *) malloc(len + 1);
    memcpy(buf, str_val + size_val, len);
    buf[len] = 0;
    return buf;
}

char *EncodersClass::sDecode_(char *str_val, int size_val) {
    char length_buf[8];
    memcpy(length_buf, str_val, size_val);
    length_buf[size_val] = 0;
    int len = iDecodeRaw(length_buf);

    char *buf = (char *) malloc(strlen(str_val) + 1);
    strcpy(buf, str_val + size_val + len);
    return buf;
}

char *EncodersClass::sSubstring(char *str_val, int size_val) {
    char length_buf[8];
    memcpy(length_buf, str_val, size_val);
    length_buf[size_val] = 0;
    int len = iDecodeRaw(length_buf);

    char *buf = (char *) malloc(size_val + len + 1);
    memcpy(buf, str_val, size_val + len);
    buf[size_val + len] = 0;
    return buf;
}

char *EncodersClass::sSubstring_(char *str_val, int size_val) {
    char length_buf[8];
    memcpy(length_buf, str_val, size_val);
    length_buf[size_val] = 0;
    int len = iDecodeRaw(length_buf);

    char *buf = (char *) malloc(strlen(str_val) + 1);
    strcpy(buf, str_val + size_val + len);
    return buf;
}
