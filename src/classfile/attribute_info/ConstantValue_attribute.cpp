#include "ConstantValue_attribute.h"

ConstantValue_attribute::ConstantValue_attribute(std::shared_ptr<ConstantInfo> constantInfo) : constantInfo(constantInfo) {}

std::shared_ptr<ConstantInfo> ConstantValue_attribute::getLinkedConstantInfo() const
{
    return constantInfo;
}