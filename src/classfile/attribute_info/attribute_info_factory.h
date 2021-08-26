#ifndef TOY_JVM_ATTRIBUTE_INFO_FACTORY_H
#define TOY_JVM_ATTRIBUTE_INFO_FACTORY_H

#include "Attribute_Info.h"
#include "../constant_pool/ConstantPool.h"
#include "memory"

std::shared_ptr<Attribute_Info> createAttributeInfo(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, std::shared_ptr<ConstantPool> constantPool);

#endif