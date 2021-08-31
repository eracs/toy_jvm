#include "StackMapTable_attribute.h"

StackMapTable_attribute::StackMapTable_attribute(std::string attributeName, u4 attributeLength,
                                                 const unsigned char *data, size_t &current_ptr,
                                                 const size_t &dataSize, int &status)
    : Attribute_Info(attributeName, attributeLength)
{
    //todo It's too complicated. skip it 
    current_ptr += attributeLength;
}
