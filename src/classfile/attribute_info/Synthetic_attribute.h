#ifndef TOY_JVM_SYNTHETIC_ATTRIBUTE_H
#define TOY_JVM_SYNTHETIC_ATTRIBUTE_H

#include "Attribute_Info.h"

class Synthetic_attribute : public Attribute_Info
{

public:
    Synthetic_attribute(std::string attributeName, u4 attributeLength);
};

#endif