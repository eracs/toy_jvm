#include "CONSTANT_Long_info.h"

CONSTANT_Long_info::CONSTANT_Long_info(u1 tag, u4 highBytes, u4 lowBytes)
    : ConstantInfo(tag), high_bytes(highBytes), low_bytes(lowBytes) {}

u4 CONSTANT_Long_info::getHighBytes() const
{
    return high_bytes;
}

u4 CONSTANT_Long_info::getLowBytes() const
{
    return low_bytes;
}
