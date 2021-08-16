#include "ClassFile.h"
#include "class_reader.h"

ClassFile::ClassFile(const unsigned char *data, const size_t &dataSize, int &status)
{
    status = 0;
    if (data != nullptr && dataSize > 0)
    {
        status = 1;
    }
    size_t current_ptr = 0;
    if (status)
    {
        magicNumber = readNextU4(data, current_ptr, dataSize, status);
    }
    if (status)
    {
        minor_version = readNextU2(data, current_ptr, dataSize, status);
    }
    if (status)
    {
        major_version = readNextU2(data, current_ptr, dataSize, status);
    }
    if (status)
    {
        constant_pool_count = readNextU2(data, current_ptr, dataSize, status);
    }
    if (status)
    {
        constantPool = new ConstantPool(data, current_ptr, dataSize, status, constant_pool_count);
    }
    else
    {
        constantPool = nullptr;
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
    if (constantPool != nullptr)
    {
        delete constantPool;
    }
}
