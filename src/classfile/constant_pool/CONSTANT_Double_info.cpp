#include "CONSTANT_Double_info.h"
#include "../../utils/data_format_util.h"

CONSTANT_Double_info::CONSTANT_Double_info(u1 tag, u4 highBytes, u4 lowBytes)
    : ConstantInfo(tag),
      high_bytes(highBytes),
      low_bytes(lowBytes)
{
    value = mergeToLong(high_bytes, low_bytes);
}

u4 CONSTANT_Double_info::getHighBytes() const
{
    return high_bytes;
}

u4 CONSTANT_Double_info::getLowBytes() const
{
    return low_bytes;
}

double CONSTANT_Double_info::getValue() const
{
    return uint64ToDouble(value);
}

bool CONSTANT_Double_info::isPositiveInfinity() const
{
    return value == 0x7ff0000000000000LL;
}

bool CONSTANT_Double_info::isNegativeInfinity() const
{
    return value == 0xfff0000000000000LL;
}

bool CONSTANT_Double_info::isNaN() const
{
    return (value >= 0x7ff0000000000001LL && value <= 0x7fffffffffffffffLL) || (value >= 0xfff0000000000001LL && value <= 0xffffffffffffffffLL);
}