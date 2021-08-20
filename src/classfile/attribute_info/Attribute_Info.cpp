#include "Attribute_Info.h"

Attribute_Info::Attribute_Info(std::string attributeName, u4 attributeLength) : attributeName(std::move(attributeName)), attributeLength(attributeLength) {}

std::string Attribute_Info::getAttributeName() const
{
    return attributeName;
}

u4 Attribute_Info::getAttributeLength() const
{
    return attributeLength;
}