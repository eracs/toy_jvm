#include "CONSTANT_Class_info.h"

CONSTANT_Class_info::CONSTANT_Class_info(u1 tag, u2 nameIndex)
    : ConstantInfo(tag), name_index(nameIndex) {}

u2 CONSTANT_Class_info::getNameIndex() const
{
    return name_index;
}
