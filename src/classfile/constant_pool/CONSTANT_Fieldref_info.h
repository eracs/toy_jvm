#ifndef TOY_JVM_CONSTANT_FIELDREF_INFO_H
#define TOY_JVM_CONSTANT_FIELDREF_INFO_H

#include "ConstantInfo.h"

class CONSTANT_Fieldref_info : public ConstantInfo
{
private:
    u2 class_index;
    u2 name_and_type_index;

public:
    CONSTANT_Fieldref_info(u1 tag, u2 classIndex, u2 nameAndTypeIndex);

    u2 getClassIndex() const;

    u2 getNameAndTypeIndex() const;
};

#endif //TOY_JVM_CONSTANT_FIELDREF_INFO_H
