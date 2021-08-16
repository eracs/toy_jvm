#ifndef TOY_JVM_CONSTANT_INVOKEDYNAMIC_INFO_H
#define TOY_JVM_CONSTANT_INVOKEDYNAMIC_INFO_H

#include "ConstantInfo.h"

class CONSTANT_InvokeDynamic_info : ConstantInfo
{
private:
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;

public:
    CONSTANT_InvokeDynamic_info(u1 tag, u2 bootstrapMethodAttrIndex, u2 nameAndTypeIndex);

    u2 getBootstrapMethodAttrIndex() const;

    u2 getNameAndTypeIndex() const;
};

#endif //TOY_JVM_CONSTANT_INVOKEDYNAMIC_INFO_H
