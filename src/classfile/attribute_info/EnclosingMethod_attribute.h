#ifndef TOY_JVM_ENCLOSINGMETHOD_ATTRIBUTE_H__
#define TOY_JVM_ENCLOSINGMETHOD_ATTRIBUTE_H__

#include "Attribute_Info.h"

class EnclosingMethod_attribute : public Attribute_Info
{
private:
    u2 class_index;
    u2 method_index;

public:
    EnclosingMethod_attribute(std::string attributeName, u4 attributeLength, u2 classIndex, u2 methodIndex);

    u2 getClassIndex() const;

    u2 getMethodIndex() const;
};

#endif // __ENCLOSINGMETHOD_ATTRIBUTE_H__