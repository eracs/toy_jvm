#include "data_format_util.h"

int u4toInt(u4 bytes)
{
    return *reinterpret_cast<int *>(&bytes);
}