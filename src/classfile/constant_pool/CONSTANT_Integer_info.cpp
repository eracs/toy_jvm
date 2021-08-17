#include "CONSTANT_Integer_info.h"
#include "../../utils/data_format_util.h"

CONSTANT_Integer_info::CONSTANT_Integer_info(u1 tag, u4 bytes)
    : ConstantInfo(tag)
{
    value = u4toInt(bytes);
}

int CONSTANT_Integer_info::getValue() const
{
    return value;
}
