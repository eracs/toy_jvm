#include "Member_Info.h"

u2 Member_Info::getAccessFlags() const
{
    return access_flags;
}

u2 Member_Info::getNameIndex() const
{
    return name_index;
}

u2 Member_Info::getDescriptorIndex() const
{
    return descriptor_index;
}

u2 Member_Info::getAttributesCount() const
{
    return attributes_count;
}

const std::vector<std::shared_ptr<Attribute_Info>> &Member_Info::getAttributes() const
{
    return attributes;
}
