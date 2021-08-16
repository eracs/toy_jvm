#include "CONSTANT_MethodHandle_info.h"

CONSTANT_MethodHandle_info::CONSTANT_MethodHandle_info(u1 tag, u1 referenceKind, u2 referenceIndex)
    : ConstantInfo(tag), reference_kind(referenceKind), reference_index(referenceIndex) {}

u1 CONSTANT_MethodHandle_info::getReferenceKind() const
{
    return reference_kind;
}

u2 CONSTANT_MethodHandle_info::getReferenceIndex() const
{
    return reference_index;
}
