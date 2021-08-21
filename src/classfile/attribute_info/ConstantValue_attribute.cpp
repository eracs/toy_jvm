#include "ConstantValue_attribute.h"

ConstantValue_attribute::ConstantValue_attribute(std::string attributeName, u4 attributeLength, std::shared_ptr<ConstantInfo> constantInfo) : Attribute_Info(attributeName, attributeLength), constantInfo(constantInfo) {}

std::shared_ptr<ConstantInfo> ConstantValue_attribute::getLinkedConstantInfo() const
{
    return constantInfo;
}