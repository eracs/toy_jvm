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
#include "../class_reader.h"
#include "../constant_pool/CONSTANT_Utf8_info.h"

std::shared_ptr<Attribute_Info> createAttributeInfo(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, std::shared_ptr<ConstantPool> constantPool)
{
    spdlog::get("Logger")->debug("Attribute:read attribute");

    u2 attribute_name_index = readNextU2(data, current_ptr, dataSize, status);
    u4 attribute_length = readNextU4(data, current_ptr, dataSize, status);
    std::shared_ptr<ConstantInfo> utf8Info = constantPool->getItems()[attribute_name_index];
    if (utf8Info->getTag() == 1)
    {
        std::string attributeName = std::static_pointer_cast<CONSTANT_Utf8_info>(utf8Info)->getUtf8Str();
    }
    current_ptr += attribute_length;
    std::shared_ptr<Attribute_Info> empty(nullptr);
    return empty;
}