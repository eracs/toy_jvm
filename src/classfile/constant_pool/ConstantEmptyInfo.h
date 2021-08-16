#ifndef TOY_JVM_CONSTANTEMPTYINFO_H
#define TOY_JVM_CONSTANTEMPTYINFO_H

#include "ConstantInfo.h"
#include <memory>

class ConstantEmptyInfo : public ConstantInfo
{
private:

public:
    ConstantEmptyInfo() : ConstantInfo(0)
    {
    }

    static std::shared_ptr<ConstantEmptyInfo> &get_instance()
    {
        // static ConstantEmptyInfo m_instance;
        static std::shared_ptr<ConstantEmptyInfo> m_instance = std::make_shared<ConstantEmptyInfo>();
        return m_instance;
    }
};

#endif //TOY_JVM_CONSTANTEMPTYINFO_H
