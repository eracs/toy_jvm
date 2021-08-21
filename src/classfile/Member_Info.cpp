#include "Member_Info.h"
#include "class_reader.h"
#include "attribute_info/attribute_info_factory.h"

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

Member_Info::Member_Info(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, ConstantPool *constantPool)
{

    access_flags = readNextU2(data, current_ptr, dataSize, status);

    name_index = readNextU2(data, current_ptr, dataSize, status);

    descriptor_index = readNextU2(data, current_ptr, dataSize, status);

    attributes_count = readNextU2(data, current_ptr, dataSize, status);

    u2 i = 0;
    while (status && i < attributes_count)
    {
        attributes.emplace_back(createAttributeInfo(data, current_ptr, dataSize, status, constantPool));
        i++;
    }
}
