#include "CONSTANT_NameAndType_info.h"

CONSTANT_NameAndType_info::CONSTANT_NameAndType_info(u1 tag, u2 nameIndex, u2 descriptorIndex)
    : ConstantInfo(tag), name_index(nameIndex), descriptor_index(descriptorIndex) {}

u2 CONSTANT_NameAndType_info::getNameIndex() const
{
    return name_index;
}

u2 CONSTANT_NameAndType_info::getDescriptorIndex() const
{
    return descriptor_index;
}
