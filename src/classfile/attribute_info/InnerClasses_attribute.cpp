#include "InnerClasses_attribute.h"
InnerClassItem::InnerClassItem(u2 inner_class_info_index,
                               u2 outer_class_info_index,
                               u2 inner_name_index,
                               u2 inner_class_access_flags) : inner_class_info_index(inner_class_info_index), outer_class_info_index(outer_class_info_index), inner_name_index(inner_name_index), inner_class_access_flags(inner_class_access_flags)
{
}

u2 InnerClassItem::getInnerClassInfoIndex() const
{
    return inner_class_info_index;
}

u2 InnerClassItem::getOuterClassInfoIndex() const
{
    return outer_class_info_index;
}

u2 InnerClassItem::getInnerNameIndex() const
{
    return inner_name_index;
}

u2 InnerClassItem::getInnerClassAccessFlags() const
{
    return inner_class_access_flags;
}

InnerClasses_attribute::InnerClasses_attribute(std::string attributeName,
                                               u4 attributeLength,
                                               u2 number_of_classes,
                                               std::vector<InnerClassItem> classes) : Attribute_Info(attributeName, attributeLength), number_of_classes(number_of_classes), classes(classes)
{
}

u2 InnerClasses_attribute::getNumberOfClasses() const
{
    return number_of_classes;
}

std::vector<InnerClassItem> InnerClasses_attribute::getClasses() const
{
    return classes;
}
