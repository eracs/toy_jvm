#include "CONSTANT_Double_info.h"

CONSTANT_Double_info::CONSTANT_Double_info(u1 tag, u4 highBytes, u4 lowBytes)
    : ConstantInfo(tag),
      high_bytes(highBytes),
      low_bytes(lowBytes) {}

u4 CONSTANT_Double_info::getHighBytes() const
{
    return high_bytes;
}

u4 CONSTANT_Double_info::getLowBytes() const
{
    return low_bytes;
}
