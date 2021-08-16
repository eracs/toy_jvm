#include "CONSTANT_InterfaceMethodref_info.h"

CONSTANT_InterfaceMethodref_info::CONSTANT_InterfaceMethodref_info(u1 tag, u2 classIndex, u2 nameAndTypeIndex)
    : ConstantInfo(tag), class_index(classIndex), name_and_type_index(nameAndTypeIndex) {}

u2 CONSTANT_InterfaceMethodref_info::getClassIndex() const
{
    return class_index;
}

u2 CONSTANT_InterfaceMethodref_info::getNameAndTypeIndex() const
{
    return name_and_type_index;
}
