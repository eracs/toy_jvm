#ifndef TOY_JVM_CONSTANTINFO_H
#define TOY_JVM_CONSTANTINFO_H

using u1 = unsigned char;
using u2 = unsigned short;
using u4 = unsigned int;

class ConstantInfo
{
private:
    u1 tag;

public:
    ConstantInfo(u1 tag);

    u1 getTag() const;
};

#endif //TOY_JVM_CONSTANTINFO_H
