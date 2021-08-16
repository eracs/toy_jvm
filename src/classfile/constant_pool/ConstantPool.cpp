#include "../class_reader.h"
#include "ConstantPool.h"
#include "ConstantInfo.h"
#include "ConstantEmptyInfo.h"
#include "CONSTANT_Class_info.h"
#include "CONSTANT_Fieldref_info.h"
#include "CONSTANT_Methodref_info.h"
#include "CONSTANT_InterfaceMethodref_info.h"
#include "CONSTANT_String_info.h"
#include "CONSTANT_Integer_info.h"
#include "CONSTANT_Float_info.h"
#include "CONSTANT_Long_info.h"
#include "CONSTANT_Double_info.h"
#include "CONSTANT_NameAndType_info.h"
#include "CONSTANT_Utf8_info.h"
#include "CONSTANT_MethodHandle_info.h"
#include "CONSTANT_MethodType_info.h"
#include "CONSTANT_InvokeDynamic_info.h"

using namespace std;

void createConstantInfo(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, vector<shared_ptr<ConstantInfo>> &container)
{
    u1 tag = readNextU1(data, current_ptr, dataSize, status);
    if (status)
    {
        if (tag == 7)
        {
            u2 name_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_Class_info>(tag, name_index));
        }
        if (tag == 9)
        {
            u2 class_index = readNextU2(data, current_ptr, dataSize, status);
            u2 name_and_type_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_Fieldref_info>(tag, class_index, name_and_type_index));
        }
        if (tag == 10)
        {
            u2 class_index = readNextU2(data, current_ptr, dataSize, status);
            u2 name_and_type_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_Methodref_info>(tag, class_index, name_and_type_index));
        }
        if (tag == 11)
        {
            u2 class_index = readNextU2(data, current_ptr, dataSize, status);
            u2 name_and_type_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_InterfaceMethodref_info>(tag, class_index, name_and_type_index));
        }
        if (tag == 8)
        {
            u2 string_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_String_info>(tag, string_index));
        }
        if (tag == 3)
        {
            u4 bytes = readNextU4(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_Integer_info>(tag, bytes));
        }
        if (tag == 4)
        {
            u4 bytes = readNextU4(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_Float_info>(tag, bytes));
        }
        if (tag == 5)
        {
            u4 high_bytes = readNextU4(data, current_ptr, dataSize, status);
            u4 low_bytes = readNextU4(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_Long_info>(tag, high_bytes, low_bytes));
        }
        if (tag == 6)
        {
            u4 high_bytes = readNextU4(data, current_ptr, dataSize, status);
            u4 low_bytes = readNextU4(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_Double_info>(tag, high_bytes, low_bytes));
        }
        if (tag == 12)
        {
            u2 name_index = readNextU2(data, current_ptr, dataSize, status);
            u2 descriptor_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_NameAndType_info>(tag, name_index, descriptor_index));
        }
        if (tag == 1)
        {
            u2 length = readNextU2(data, current_ptr, dataSize, status);
            char *str = new char[length + 1];
            for (int i = 0; i < length; i++)
            {
                str[i] = readNextU1(data, current_ptr, dataSize, status);
            }
            str[length] = '\0';
            string utf8_str(str);
            delete[] str;
            container.emplace_back(make_shared<CONSTANT_Utf8_info>(tag, length, utf8_str));
        }
        if (tag == 15)
        {
            u1 reference_kind = readNextU1(data, current_ptr, dataSize, status);
            u2 reference_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_MethodHandle_info>(tag, reference_kind, reference_index));
        }
        if (tag == 16)
        {
            u2 descriptor_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_MethodType_info>(tag, descriptor_index));
        }
        if (tag == 18)
        {
            u2 bootstrap_method_attr_index = readNextU2(data, current_ptr, dataSize, status);
            u2 name_and_type_index = readNextU2(data, current_ptr, dataSize, status);
            container.emplace_back(make_shared<CONSTANT_InvokeDynamic_info>(tag, bootstrap_method_attr_index, name_and_type_index));
        }
    }
}

ConstantPool::ConstantPool(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status,
                           const u2 &constant_pool_count) : constant_pool_count(constant_pool_count)
{
    int i = 1;
    while (status && i < constant_pool_count)
    {
        createConstantInfo(data, current_ptr, dataSize, status, ConstantPool::items);
        i++;
    }
}

const shared_ptr<ConstantInfo> &ConstantPool::operator[](int index) const
{
    index--;
    if (index <= 0 || index >= items.size())
        return ConstantEmptyInfo::get_instance();
    return items[index];
}

shared_ptr<ConstantInfo> ConstantPool::operator[](int index)
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

const vector<shared_ptr<ConstantInfo>> &ConstantPool::getItems() const
{
    return items;
}
