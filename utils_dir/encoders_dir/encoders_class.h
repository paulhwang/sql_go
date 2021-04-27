/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef ENCODERS_CLASS_H
#define ENCODERS_CLASS_H

class EncodersClass {
public:
    static const int DATA_LENGTH_SIZE = 2;

    EncodersClass();
    ~EncodersClass();

    static char *iEncodeRaw(int number_val, int size_val);
    static char *iEncodeRaw1(int number_val) { return iEncodeRaw(number_val, 1); }
    static char *iEncodeRaw2(int number_val) { return iEncodeRaw(number_val, 2); }
    static char *iEncodeRaw3(int number_val) { return iEncodeRaw(number_val, 3); }
    static char *iEncodeRaw4(int number_val) { return iEncodeRaw(number_val, 4); }
    static char *iEncodeRaw5(int number_val) { return iEncodeRaw(number_val, 5); }
    static char *iEncodeRaw6(int number_val) { return iEncodeRaw(number_val, 6); }
    
    static char *iEncodeLen(int number_val, int size_val);
    static char *iEncodeLen1(int number_val) { return iEncodeLen(number_val, 1); }
    static char *iEncodeLen2(int number_val) { return iEncodeLen(number_val, 2); }
    static char *iEncodeLen3(int number_val) { return iEncodeLen(number_val, 3); }
    static char *iEncodeLen4(int number_val) { return iEncodeLen(number_val, 4); }
    static char *iEncodeLen5(int number_val) { return iEncodeLen(number_val, 5); }
    static char *iEncodeLen6(int number_val) { return iEncodeLen(number_val, 6); }

    static int iDecodeRaw(char *str_val);
	static int iDecodeLen(char *str_val);

    static char *sEncode(char *str_val, int size_val);
    static char *sEncode1(char *str_val) { return sEncode(str_val, 1); }
    static char *sEncode2(char *str_val) { return sEncode(str_val, 2); }
    static char *sEncode3(char *str_val) { return sEncode(str_val, 3); }
    static char *sEncode4(char *str_val) { return sEncode(str_val, 4); }
    static char *sEncode5(char *str_val) { return sEncode(str_val, 5); }
    static char *sEncode6(char *str_val) { return sEncode(str_val, 6); }

	static char *sDecode(char *str_val, int size_val);
    static char *sDecode1(char *str_val) { return sDecode(str_val, 1); }
    static char *sDecode2(char *str_val) { return sDecode(str_val, 2); }
    static char *sDecode3(char *str_val) { return sDecode(str_val, 3); }
    static char *sDecode4(char *str_val) { return sDecode(str_val, 4); }
    static char *sDecode5(char *str_val) { return sDecode(str_val, 5); }
    static char *sDecode6(char *str_val) { return sDecode(str_val, 6); }

    static char *sDecode_(char *str_val, int size_val);
    static char *sDecode1_(char *str_val) { return sDecode_(str_val, 1); }
    static char *sDecode2_(char *str_val) { return sDecode_(str_val, 2); }
    static char *sDecode3_(char *str_val) { return sDecode_(str_val, 3); }
    static char *sDecode4_(char *str_val) { return sDecode_(str_val, 4); }
    static char *sDecode5_(char *str_val) { return sDecode_(str_val, 5); }
    static char *sDecode6_(char *str_val) { return sDecode_(str_val, 6); }

    static char *sSubstring(char *str_val, int size_val);
    static char *sSubstring1(char *str_val) { return sSubstring(str_val, 1); }
    static char *sSubstring2(char *str_val) { return sSubstring(str_val, 2); }
    static char *sSubstring3(char *str_val) { return sSubstring(str_val, 3); }
    static char *sSubstring4(char *str_val) { return sSubstring(str_val, 4); }
    static char *sSubstring5(char *str_val) { return sSubstring(str_val, 5); }
    static char *sSubstring6(char *str_val) { return sSubstring(str_val, 6); }

    static char *sSubstring_(char *str_val, int size_val);
    static char *sSubstring1_(char *str_val) { return sSubstring_(str_val, 1); }
    static char *sSubstring2_(char *str_val) { return sSubstring_(str_val, 2); }
    static char *sSubstring3_(char *str_val) { return sSubstring_(str_val, 3); }
    static char *sSubstring4_(char *str_val) { return sSubstring_(str_val, 4); }
    static char *sSubstring5_(char *str_val) { return sSubstring_(str_val, 5); }
    static char *sSubstring6_(char *str_val) { return sSubstring_(str_val, 6); }

    static void subString(const char *from_str_val, char *to_str_val, int from_val, int to_val);

};

#endif
