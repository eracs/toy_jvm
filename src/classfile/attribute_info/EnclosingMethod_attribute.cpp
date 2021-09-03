#include "EnclosingMethod_attribute.h"
EnclosingMethod_attribute::EnclosingMethod_attribute(std::string attributeName,
                                                     u4 attributeLength, u2 classIndex, u2 methodIndex)
    : Attribute_Info(attributeName, attributeLength), class_index(classIndex), method_index(methodIndex) {}

u2 EnclosingMethod_attribute::getClassIndex() const
{
    return class_index;
}

u2 EnclosingMethod_attribute::getMethodIndex() const
{
    return method_index;
}
