#ifndef TOY_JVM_DATA_FORMAT_UTIL_H
#define TOY_JVM_DATA_FORMAT_UTIL_H

#include "../type_format.h"

int u4toInt(u4 bytes);

float u4toFloat(u4 bytes);

uint64_t mergeToLong(u4 high_bytes, u4 low_bytes);

long long uint64ToLong(uint64_t value);

double uint64ToDouble(uint64_t value);

#endif