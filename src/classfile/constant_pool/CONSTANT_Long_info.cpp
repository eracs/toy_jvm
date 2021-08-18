#include "CONSTANT_Long_info.h"
#include "../../utils/data_format_util.h"

CONSTANT_Long_info::CONSTANT_Long_info(u1 tag, u4 highBytes, u4 lowBytes)
    : ConstantInfo(tag), high_bytes(highBytes), low_bytes(lowBytes)
{
    value = mergeToLong(high_bytes, low_bytes);
}

u4 CONSTANT_Long_info::getHighBytes() const
{
    return high_bytes;
}

u4 CONSTANT_Long_info::getLowBytes() const
{
    return low_bytes;
}

uint64_t CONSTANT_Long_info::getValue() const
{
    return value;
}