#ifndef TOY_JVM_CONSTANT_METHODTYPE_INFO_H
#define TOY_JVM_CONSTANT_METHODTYPE_INFO_H

#include "ConstantInfo.h"

class CONSTANT_MethodType_info : ConstantInfo
{
private:
    u2 descriptor_index;

public:
    CONSTANT_MethodType_info(u1 tag, u2 descriptorIndex);

    u2 getDescriptorIndex() const;
};

#endif //TOY_JVM_CONSTANT_METHODTYPE_INFO_H
