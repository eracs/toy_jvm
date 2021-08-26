#ifndef TOY_JVM_MEMBERINFO_H
#define TOY_JVM_MEMBERINFO_H

#include "attribute_info/Attribute_Info.h"
#include <vector>
#include <memory>
#include "constant_pool/ConstantPool.h"

class Member_Info
{
private:
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    std::vector<std::shared_ptr<Attribute_Info>> attributes;

public:
    Member_Info() = delete;

    Member_Info(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, std::shared_ptr<ConstantPool> constantPool);

    u2 getAccessFlags() const;

    u2 getNameIndex() const;

    u2 getDescriptorIndex() const;

    u2 getAttributesCount() const;

    const std::vector<std::shared_ptr<Attribute_Info>> &getAttributes() const;
};

#endif //TOY_JVM_MEMBERINFO_H
