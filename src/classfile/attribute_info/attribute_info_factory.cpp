#include "attribute_info_factory.h"
#include "spdlog/spdlog.h"
#include "Code_attribute.h"
#include "ConstantValue_attribute.h"
#include "Deprecated_attribute.h"
#include "Synthetic_attribute.h"
#include "SourceFile_attribute.h"
#include "Exceptions_attribute.h"
#include "LineNumberTable_attribute.h"
#include "StackMapTable_attribute.h"
#include "InnerClasses_attribute.h"

std::shared_ptr<Attribute_Info> createAttributeInfo(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, std::shared_ptr<ConstantPool> constantPool)
{
    spdlog::get("Logger")->debug("Attribute:read attribute");
    std::shared_ptr<Attribute_Info> empty(nullptr);
    return empty;
}