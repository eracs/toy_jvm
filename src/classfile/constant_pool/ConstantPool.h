#ifndef TOY_JVM_CONSTANTPOOL_H
#define TOY_JVM_CONSTANTPOOL_H

#include <vector>
#include "ConstantInfo.h"


class ConstantPool {
private:
    u2 constant_pool_count;
    std::vector<ConstantInfo> items;

public:
    ConstantPool() = delete;

    ConstantPool(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status,
                 const u2 &constant_pool_count);

    u2 getConstantPoolCount() const;

    const std::vector<ConstantInfo> &getItems() const;

    ConstantInfo &operator[](int index);

    const ConstantInfo &operator[](int index) const;
};

#endif //TOY_JVM_CONSTANTPOOL_H
