#include "CONSTANT_Integer_info.h"

CONSTANT_Integer_info::CONSTANT_Integer_info(u1 tag, u4 bytes)
    : ConstantInfo(tag), bytes(bytes) {}

u4 CONSTANT_Integer_info::getBytes() const
{
    return bytes;
}
