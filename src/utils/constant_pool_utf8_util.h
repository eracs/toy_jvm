#include "../classfile/constant_pool/ConstantInfo.h"
#include "../classfile/constant_pool/CONSTANT_Utf8_info.h"
#include "memory"

inline std::string readUtf8Str(const ConstantInfo &info, int &status)
{
    if (info.getTag() == 1)
    {
        const ConstantInfo *ptr = &info;
        return static_cast<CONSTANT_Utf8_info *>(const_cast<ConstantInfo *>(ptr))->getUtf8Str();
    }
    status = 0;
    return "";
}
