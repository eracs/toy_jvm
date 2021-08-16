#include "CONSTANT_Utf8_info.h"

CONSTANT_Utf8_info::CONSTANT_Utf8_info(u1 tag, u2 length, std::string utf8Str) : ConstantInfo(tag),
                                                                                 length(length),
                                                                                 utf8_str(std::move(utf8Str)) {}

u2 CONSTANT_Utf8_info::getLength() const
{
    return length;
}

const std::string &CONSTANT_Utf8_info::getUtf8Str() const
{
    return utf8_str;
}
