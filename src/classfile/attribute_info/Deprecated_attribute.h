#ifndef TOY_JVM_DEPRECATED_ATTRIBUTE_H
#define TOY_JVM_DEPRECATED_ATTRIBUTE_H

#include "Attribute_Info.h"

class Deprecated_attribute : public Attribute_Info
{

public:
    Deprecated_attribute(std::string attributeName, u4 attributeLength);
};

#endif