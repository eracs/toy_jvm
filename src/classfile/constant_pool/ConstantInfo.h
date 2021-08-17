#ifndef TOY_JVM_CONSTANTINFO_H
#define TOY_JVM_CONSTANTINFO_H

#include "../../type_format.h"

class ConstantInfo
{
private:
    u1 tag;

public:
    ConstantInfo(u1 tag);

    u1 getTag() const;
};

#endif //TOY_JVM_CONSTANTINFO_H
