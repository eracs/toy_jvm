#include "CONSTANT_MethodType_info.h"

CONSTANT_MethodType_info::CONSTANT_MethodType_info(u1 tag, u2 descriptorIndex)
    : ConstantInfo(tag), descriptor_index(descriptorIndex) {}

u2 CONSTANT_MethodType_info::getDescriptorIndex() const
{
    return descriptor_index;
}
