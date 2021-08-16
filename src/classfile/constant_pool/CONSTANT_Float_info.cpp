#include "CONSTANT_Float_info.h"

u4 CONSTANT_Float_info::getBytes() const
{
    return bytes;
}

CONSTANT_Float_info::CONSTANT_Float_info(u1 tag, u4 bytes) : ConstantInfo(tag), bytes(bytes) {}
