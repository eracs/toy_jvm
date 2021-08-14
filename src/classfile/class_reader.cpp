#include "class_reader.h"

u1 readNextU1(const unsigned char *data, size_t &current_ptr, const size_t &length, int &status)
{
    status = 0;
    if (current_ptr <= length - 1)
    {
        status = 1;
        return data[current_ptr++];
    }
    return 0;
}

u2 readNextU2(const unsigned char *data, size_t &current_ptr, const size_t &length, int &status)
{
    u2 value = 0;
    status = 0;
    if (current_ptr <= length - 2)
    {
        value += data[current_ptr++] << 8;
        value += data[current_ptr++];
        status = 1;
    }

    return value;
}

u4 readNextU4(const unsigned char *data, size_t &current_ptr, const size_t &length, int &status)
{
    u4 value = 0;
    status = 0;
    if (current_ptr <= length - 4)
    {
        value += data[current_ptr++] << 24;
        value += data[current_ptr++] << 16;
        value += data[current_ptr++] << 8;
        value += data[current_ptr++];
        status = 1;
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