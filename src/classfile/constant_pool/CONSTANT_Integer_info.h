#ifndef TOY_JVM_CONSTANT_INTEGER_INFO_H
#define TOY_JVM_CONSTANT_INTEGER_INFO_H

#include "ConstantInfo.h"

class CONSTANT_Integer_info : public ConstantInfo
{
private:
    int value;

public:
    CONSTANT_Integer_info(u1 tag, u4 bytes);

    int getValue() const;
};

#endif //TOY_JVM_CONSTANT_INTEGER_INFO_H
