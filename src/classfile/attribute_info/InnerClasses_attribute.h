#ifndef TOY_JVM_INNERCLASSES_ATTRIBUTE_H__
#define TOY_JVM_INNERCLASSES_ATTRIBUTE_H__

#include "Attribute_Info.h"
#include <vector>

class InnerClassItem
{
private:
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags;

public:
    InnerClassItem(u2 inner_class_info_index,
                   u2 outer_class_info_index,
                   u2 inner_name_index,
                   u2 inner_class_access_flags);
    u2 getInnerClassInfoIndex() const;
    u2 getOuterClassInfoIndex() const;
    u2 getInnerNameIndex() const;
    u2 getInnerClassAccessFlags() const;
};

class InnerClasses_attribute : public Attribute_Info
{
private:
    u2 number_of_classes;
    std::vector<InnerClassItem> classes;

public:
    InnerClasses_attribute(
        std::string attributeName,
        u4 attributeLength,
        u2 number_of_classes,
        std::vector<InnerClassItem> classes);

    u2 getNumberOfClasses() const;
    std::vector<InnerClassItem> getClasses() const;
};

#endif // TOY_JVM_INNERCLASSES_ATTRIBUTE_H__