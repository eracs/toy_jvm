#include "CONSTANT_InvokeDynamic_info.h"

CONSTANT_InvokeDynamic_info::CONSTANT_InvokeDynamic_info(u1 tag, u2 bootstrapMethodAttrIndex, u2 nameAndTypeIndex)
    : ConstantInfo(tag), bootstrap_method_attr_index(bootstrapMethodAttrIndex), name_and_type_index(nameAndTypeIndex) {}

u2 CONSTANT_InvokeDynamic_info::getBootstrapMethodAttrIndex() const
{
    return bootstrap_method_attr_index;
}

u2 CONSTANT_InvokeDynamic_info::getNameAndTypeIndex() const
{
    return name_and_type_index;
}
