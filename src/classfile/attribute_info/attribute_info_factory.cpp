#include "attribute_info_factory.h"
#include "Code_attribute.h"
#include "ConstantValue_attribute.h"
#include "Deprecated_attribute.h"
#include "Synthetic_attribute.h"


std::shared_ptr<Attribute_Info> createAttributeInfo(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, ConstantPool *constantPool)
{
    std::shared_ptr<Attribute_Info> empty(nullptr);
    return empty;
}