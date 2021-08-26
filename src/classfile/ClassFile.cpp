#include "ClassFile.h"
#include "class_reader.h"
#include "attribute_info/attribute_info_factory.h"
#include "spdlog/spdlog.h"

ClassFile::ClassFile(const unsigned char *data, const size_t &dataSize, int &status)
{
    status = 0;
    spdlog::get("Logger")->debug("ClassFile:start parse class file");
    if (data != nullptr && dataSize > 0)
    {
        status = 1;
        size_t current_ptr = 0;

        spdlog::get("Logger")->debug("ClassFile:read magicNumber");
        magicNumber = readNextU4(data, current_ptr, dataSize, status);

        minor_version = readNextU2(data, current_ptr, dataSize, status);

        major_version = readNextU2(data, current_ptr, dataSize, status);

        spdlog::get("Logger")->debug("ClassFile:read constantPool");
        constant_pool_count = readNextU2(data, current_ptr, dataSize, status);

        if (status)
        {
            constantPool = std::make_shared<ConstantPool>(data, current_ptr, dataSize, status, constant_pool_count);
        }
        else
        {
            constantPool = nullptr;
        }

        spdlog::get("Logger")->debug("ClassFile:read from access flag to interfaces");
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

        spdlog::get("Logger")->debug("ClassFile:read fields");
        fields_count = readNextU2(data, current_ptr, dataSize, status);

        i = 0;
        while (status && i < fields_count && constantPool != nullptr)
        {
            fields.emplace_back(std::make_shared<Member_Info>(data, current_ptr, dataSize, status, constantPool));
            i++;
        }

        spdlog::get("Logger")->debug("ClassFile:read methods");
        methods_count = readNextU2(data, current_ptr, dataSize, status);

        i = 0;
        while (status && i < methods_count && constantPool != nullptr)
        {
            methods.emplace_back(std::make_shared<Member_Info>(data, current_ptr, dataSize, status, constantPool));
            i++;
        }

        spdlog::get("Logger")->debug("ClassFile:read attributes");
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
    spdlog::get("Logger")->debug("ClassFile:finish parse class file");
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

std::shared_ptr<ConstantPool> ClassFile::getConstantPool() const
{
    return constantPool;
}
