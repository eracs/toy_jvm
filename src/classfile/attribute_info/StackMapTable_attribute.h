#ifndef TOY_JVM_STACKMAPTABLE_ATTRIBUTE_H__
#define TOY_JVM_STACKMAPTABLE_ATTRIBUTE_H__

#include "Attribute_Info.h"

class StackMapTable_attribute : public Attribute_Info
{
 
private:
public:

    StackMapTable_attribute(std::string attributeName, u4 attributeLength, const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status);
};

#endif // TOY_JVM_STACKMAPTABLE_ATTRIBUTE_H__