#ifndef TOY_JVM_CONSTANT_METHODHANDLE_INFO_H
#define TOY_JVM_CONSTANT_METHODHANDLE_INFO_H

#include "ConstantInfo.h"

class CONSTANT_MethodHandle_info : ConstantInfo
{
private:
    u1 reference_kind;
    u2 reference_index;

public:
    CONSTANT_MethodHandle_info(u1 tag, u1 referenceKind, u2 referenceIndex);

    u1 getReferenceKind() const;

    u2 getReferenceIndex() const;
};

#endif //TOY_JVM_CONSTANT_METHODHANDLE_INFO_H
