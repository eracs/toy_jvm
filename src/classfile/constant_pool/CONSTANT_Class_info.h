#ifndef TOY_JVM_CONSTANT_CLASS_INFO_H
#define TOY_JVM_CONSTANT_CLASS_INFO_H

#include "ConstantInfo.h"

class CONSTANT_Class_info :public ConstantInfo
{
private:
    u2 name_index;

public:
    CONSTANT_Class_info(u1 tag, u2 nameIndex);

    u2 getNameIndex() const;
};

#endif //TOY_JVM_CONSTANT_CLASS_INFO_H
