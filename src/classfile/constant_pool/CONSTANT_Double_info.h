#ifndef TOY_JVM_CONSTANT_DOUBLE_INFO_H
#define TOY_JVM_CONSTANT_DOUBLE_INFO_H

#include "ConstantInfo.h"

class CONSTANT_Double_info :public ConstantInfo
{
private:
    u4 high_bytes;
    u4 low_bytes;

public:
    CONSTANT_Double_info(u1 tag, u4 highBytes, u4 lowBytes);

    u4 getHighBytes() const;

    u4 getLowBytes() const;
};

#endif //TOY_JVM_CONSTANT_DOUBLE_INFO_H
