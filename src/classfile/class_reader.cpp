#include "class_reader.h"
#include "spdlog/spdlog.h"

u1 readNextU1(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status)
{
    if (!status)
        return 0;
    if (current_ptr <= dataSize - 1)
    {
        return data[current_ptr++];
    }
      spdlog::get("Logger")->warn("readU1 failed in postion {0}", current_ptr);
    status = 0;
    return 0;
}

u2 readNextU2(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status)
{
    u2 value = 0;

    if (!status)
        return value;
    if (current_ptr <= dataSize - 2)
    {
        value += data[current_ptr++] << 8;
        value += data[current_ptr++];
    }
    else
    {
        spdlog::get("Logger")->warn("readU2 failed in postion {0}", current_ptr);
        status = 0;
    }

    return value;
}

u4 readNextU4(const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status)
{
    u4 value = 0;

    if (!status)
        return value;
    if (current_ptr <= dataSize - 4)
    {
        value += data[current_ptr++] << 24;
        value += data[current_ptr++] << 16;
        value += data[current_ptr++] << 8;
        value += data[current_ptr++];
    }
    else
    {
         spdlog::get("Logger")->warn("readU4 failed in postion {0}", current_ptr);
        status = 0;
    }
    return value;
}

/*
    //example
    size_t dataSize = 0;
    size_t current_ptr = 0;
    auto data = ClassFileReader::get_instance().readClass("test.Main", dataSize);
    if (dataSize >= 10)
    {
        auto magicNumber = readNextU4(data, current_ptr, dataSize);
        auto minor_version = readNextU2(data, current_ptr, dataSize);
        auto major_version = readNextU2(data, current_ptr, dataSize);
        auto constant_pool_count = readNextU2(data, current_ptr, dataSize);
        spdlog::critical("magicNumber : {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", magicNumber);
        spdlog::critical("minor_version : {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", minor_version);
        spdlog::critical("major_version : {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", major_version);
        spdlog::critical("constant_pool_count : {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", constant_pool_count);
    }
*/