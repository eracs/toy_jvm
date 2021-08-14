#ifndef TOY_JVM_CONSTANTEMPTYINFO_H
#define TOY_JVM_CONSTANTEMPTYINFO_H

#include "ConstantInfo.h"

class ConstantEmptyInfo : public ConstantInfo
{
private:
    ConstantEmptyInfo() : ConstantInfo(0)
    {
    }

public:
    static ConstantEmptyInfo &get_instance()
    {
        static ConstantEmptyInfo m_instance;
        return m_instance;
    }
};

#endif //TOY_JVM_CONSTANTEMPTYINFO_H
