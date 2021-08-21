#include "ClassFile.h"
#include "class_reader.h"
#include "attribute_info/attribute_info_factory.h"

ClassFile::ClassFile(const unsigned char *data, const size_t &dataSize, int &status)
{
    status = 0;
    if (data != nullptr && dataSize > 0)
    {
        status = 1;
        size_t current_ptr = 0;

        magicNumber = readNextU4(data, current_ptr, dataSize, status);

        minor_version = readNextU2(data, current_ptr, dataSize, status);

        major_version = readNextU2(data, current_ptr, dataSize, status);

        constant_pool_count = readNextU2(data, current_ptr, dataSize, status);

        if (status)
        {
            constantPool = new ConstantPool(data, current_ptr, dataSize, status, constant_pool_count);
        }
        else
        {
            constantPool = nullptr;
        }

        access_flags = readNextU2(data, current_ptr, dataSize, status);

        this_class = readNextU2(data, current_ptr, dataSize, status);

        super_class = readNextU2(data, current_ptr, dataSize, status);

        interfaces_count = readNextU2(data, current_ptr, dataSize, status);

        u2 i = 0;
        while (status && i < interfaces_count)
        {
            interfaces.emplace_back(readNextU2(data, current_ptr, dataSize, status));
            i++;
        }

        fields_count = readNextU2(data, current_ptr, dataSize, status);

        i = 0;
        while (status && i < fields_count && constantPool != nullptr)
        {
            fields.emplace_back(std::make_shared<Member_Info>(data, current_ptr, dataSize, status, constantPool));
            i++;
        }

        methods_count = readNextU2(data, current_ptr, dataSize, status);

        i = 0;
        while (status && i < methods_count && constantPool != nullptr)
        {
            methods.emplace_back(std::make_shared<Member_Info>(data, current_ptr, dataSize, status, constantPool));
            i++;
        }

        attributes_count = readNextU2(data, current_ptr, dataSize, status);

        i = 0;
        while (status && i < attributes_count)
        {
            attributes.emplace_back(createAttributeInfo(data, current_ptr, dataSize, status, constantPool));
            i++;
        }
        if (current_ptr != dataSize)
        {
            status = 0;
        }
    }
}

u4 ClassFile::getMagicNumber() const
{
    return magicNumber;
}

u2 ClassFile::getMinorVersion() const
{
    return minor_version;
}

u2 ClassFile::getMajorVersion() const
{
    return major_version;
}

u2 ClassFile::getConstantPoolCount() const
{
    return constant_pool_count;
}

ConstantPool *ClassFile::getConstantPool() const
{
    return constantPool;
}

ClassFile::~ClassFile()
{

    delete constantPool;
}
