#ifndef TOY_JVM_ATTRIBUTE_INFO_H
#define TOY_JVM_ATTRIBUTE_INFO_H

#include "../class_reader.h"
#include <string>

class Attribute_Info
{
private:
    std::string attributeName;
    u4 attributeLength;

public:
    Attribute_Info(std::string attributeName, u4 attributeLength);

    std::string getAttributeName() const;

    u4 getAttributeLength() const;
};

#endif //TOY_JVM_ATTRIBUTE_INFO_H
