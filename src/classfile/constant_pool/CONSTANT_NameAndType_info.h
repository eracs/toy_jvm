#ifndef TOY_JVM_CONSTANT_NAMEANDTYPE_INFO_H
#define TOY_JVM_CONSTANT_NAMEANDTYPE_INFO_H

#include "ConstantInfo.h"

class CONSTANT_NameAndType_info :public ConstantInfo
{
private:
    u2 name_index;
    u2 descriptor_index;

public:
    CONSTANT_NameAndType_info(u1 tag, u2 nameIndex, u2 descriptorIndex);

    u2 getNameIndex() const;

    u2 getDescriptorIndex() const;
};

#endif //TOY_JVM_CONSTANT_NAMEANDTYPE_INFO_H
