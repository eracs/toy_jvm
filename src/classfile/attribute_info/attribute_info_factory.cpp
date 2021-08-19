#include "attribute_info_factory.h"

std::shared_ptr<Attribute_Info> createAttributeInfo(const unsigned char *data, size_t &current_ptr, const size_t &length, int &status, ConstantPool *contantPool)
{
    return std::make_shared<Attribute_Info>();
}