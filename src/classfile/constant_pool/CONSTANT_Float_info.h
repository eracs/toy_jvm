#ifndef TOY_JVM_CONSTANT_FLOAT_INFO_H
#define TOY_JVM_CONSTANT_FLOAT_INFO_H

#include "ConstantInfo.h"

class CONSTANT_Float_info : public ConstantInfo
{
private:
    u4 bytes;

public:
    CONSTANT_Float_info(u1 tag, u4 bytes);

    u4 getBytes() const;

    float getValue() const;

    bool isPositiveInfinity() const;

    bool isNegativeInfinity() const;

    bool isNaN() const;
};

#endif //TOY_JVM_CONSTANT_FLOAT_INFO_H
