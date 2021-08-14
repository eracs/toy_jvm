#include "ConstantInfo.h"

ConstantInfo::ConstantInfo(u1 tag) : tag(tag) {}

u1 ConstantInfo::getTag() const
{
    return tag;
}
