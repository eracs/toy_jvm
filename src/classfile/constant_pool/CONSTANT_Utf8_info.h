#ifndef TOY_JVM_CONSTANT_UTF8_INFO_H
#define TOY_JVM_CONSTANT_UTF8_INFO_H

#include "ConstantInfo.h"
#include <string>

class CONSTANT_Utf8_info : ConstantInfo
{
private:
    u2 length;
    std::string utf8_str;

public:
    CONSTANT_Utf8_info(u1 tag, u2 length, std::string utf8Str);

    u2 getLength() const;

    const std::string &getUtf8Str() const;
};

#endif //TOY_JVM_CONSTANT_UTF8_INFO_H
