#ifndef TOY_JVM_MEMBERINFO_H
#define TOY_JVM_MEMBERINFO_H

#include <vector>
#include "attribute_info/Attribute_Info.h"

class Member_Info
{
private:
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    std::vector<Attribute_Info> attributes;

public:
    u2 getAccessFlags() const;

    u2 getNameIndex() const;

    u2 getDescriptorIndex() const;

    u2 getAttributesCount() const;

    const std::vector<Attribute_Info> &getAttributes() const;
};

#endif //TOY_JVM_MEMBERINFO_H
