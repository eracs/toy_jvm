#ifndef TOY_JVM_CONSTANT_STRING_INFO_H
#define TOY_JVM_CONSTANT_STRING_INFO_H

#include "ConstantInfo.h"

class CONSTANT_String_info : public ConstantInfo
{
private:
    u2 string_index;

public:
    CONSTANT_String_info(u1 tag, u2 stringIndex);

    u2 getStringIndex() const;
};

#endif //TOY_JVM_CONSTANT_STRING_INFO_H
