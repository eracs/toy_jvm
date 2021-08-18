#include "data_format_util.h"

int u4toInt(u4 bytes)
{
    return *reinterpret_cast<int *>(&bytes);
}

float u4toFloat(u4 bytes)
{
    return *reinterpret_cast<float *>(&bytes);
}

uint64_t mergeToLong(u4 high_bytes, u4 low_bytes)
{
    uint64_t result = high_bytes;
    result <<= 32;
    result += low_bytes;
    return result;
}

double uint64ToDouble(uint64_t value)
{
    return *reinterpret_cast<double *>(&value);
}