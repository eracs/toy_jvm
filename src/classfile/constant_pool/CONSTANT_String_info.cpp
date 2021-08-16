#include "CONSTANT_String_info.h"

CONSTANT_String_info::CONSTANT_String_info(u1 tag, u2 stringIndex) : ConstantInfo(tag), string_index(stringIndex) {}

u2 CONSTANT_String_info::getStringIndex() const
{
    return string_index;
}
