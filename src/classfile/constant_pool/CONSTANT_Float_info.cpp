#include "CONSTANT_Float_info.h"
#include "../../utils/data_format_util.h"

u4 CONSTANT_Float_info::getBytes() const
{
    return bytes;
}

float CONSTANT_Float_info::getValue() const
{
    return u4toFloat(bytes);
}

CONSTANT_Float_info::CONSTANT_Float_info(u1 tag, u4 bytes) : ConstantInfo(tag), bytes(bytes) {}

bool CONSTANT_Float_info::isPositiveInfinity() const
{
    return bytes == 0x7f800000;
}

bool CONSTANT_Float_info::isNegativeInfinity() const
{
    return bytes == 0xff800000;
}

bool CONSTANT_Float_info::isNaN() const
{
    return (bytes >= 0x7f800001 && bytes <= 0x7fffffff) || (bytes >= 0xff800001 && bytes <= 0xffffffff);
}