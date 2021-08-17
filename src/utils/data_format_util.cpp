#include "data_format_util.h"

int u4toInt(unsigned int bytes)
{
    return *reinterpret_cast<int *>(&bytes);
}