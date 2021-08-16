#ifndef TOY_JVM_CONSTANTPOOL_H
#define TOY_JVM_CONSTANTPOOL_H

#include <vector>
#include <memory>
#include "ConstantInfo.h"

class ConstantPool
{
private:
    u2 constant_pool_count;
    std::vector<std::shared_ptr<ConstantInfo>> items;

public:
    ConstantPool() = delete;

    ConstantPool(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status,
                 const u2 &constant_pool_count);

    u2 getConstantPoolCount() const;

    const std::vector<std::shared_ptr<ConstantInfo>> &getItems() const;

    std::shared_ptr<ConstantInfo> operator[](int index);

    const std::shared_ptr<ConstantInfo> &operator[](int index) const;
};

#endif //TOY_JVM_CONSTANTPOOL_H
