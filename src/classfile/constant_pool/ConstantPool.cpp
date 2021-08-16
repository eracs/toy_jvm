#include "../class_reader.h"
#include "ConstantPool.h"
#include "ConstantEmptyInfo.h"

ConstantInfo &createConstantInfo(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status)
{
    u1 tag = readNextU1(data, current_ptr, dataSize, status);
    if (status)
    {
    }
    return ConstantEmptyInfo::get_instance();
}

ConstantPool::ConstantPool(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status,
                           const u2 &constant_pool_count) : constant_pool_count(constant_pool_count)
{
    while (status)
    {
        items.emplace_back(createConstantInfo(data, current_ptr, dataSize, status));
    }
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
