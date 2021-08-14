#include "ConstantPool.h"

ConstantPool::ConstantPool(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status,
                           const u2 &constant_pool_count) : constant_pool_count(constant_pool_count)
{
}

const ConstantInfo &ConstantPool::operator[](int index) const
{
    index--;
    if (index <= 0 || index >= items.size())
        return ConstantEmptyInfo::get_instance();
    return items[index];
}

ConstantInfo &ConstantPool::operator[](int index)
{
    index--;
    if (index <= 0 || index >= items.size())
        return ConstantEmptyInfo::get_instance();
    return items[index];
}

u2 ConstantPool::getConstantPoolCount() const
{
    return constant_pool_count;
}

const std::vector<ConstantInfo> &ConstantPool::getItems() const
{
    return items;
}
