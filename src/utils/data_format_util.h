#ifndef TOY_JVM_DATA_FORMAT_UTIL_H
#define TOY_JVM_DATA_FORMAT_UTIL_H

#include "../type_format.h"

//u4转有符号int
int u4toInt(u4 bytes);
//u4转float
float u4toFloat(u4 bytes);
//高位和低位合并成u8
uint64_t mergeToLong(u4 high_bytes, u4 low_bytes);
//u8转有符号long long
long long uint64ToLong(uint64_t value);
//u8转double
double uint64ToDouble(uint64_t value);

#endif