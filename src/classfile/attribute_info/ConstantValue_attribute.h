#ifndef TOY_JVM_CONSTANTVALUE_ATTRIBUTE_H
#define TOY_JVM_CONSTANTVALUE_ATTRIBUTE_H

#include "Attribute_Info.h"
#include <memory>
#include "../constant_pool/ConstantInfo.h"

class ConstantValue_attribute
{
private:
    std::shared_ptr<ConstantInfo> constantInfo;

public:
    ConstantValue_attribute(std::shared_ptr<ConstantInfo> constantInfo);

    std::shared_ptr<ConstantInfo> getLinkedConstantInfo() const;
};

/*
ConstantValue_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 constantvalue_index;
}

*/
#endif