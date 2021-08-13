#include "class_reader.h"

u1 readNextU1(unsigned char *data, size_t &current_prt, size_t length)
{
    if (current_prt <= length - 1)
    {
        return data[current_prt++];
    }
    return 0;
}

u2 readNextU2(unsigned char *data, size_t &current_prt, size_t length)
{
    u2 value = 0;
    if (current_prt <= length - 2)
    {
        value += data[current_prt++] << 8;
        value += data[current_prt++];
    }

    return value;
}

u4 readNextU4(unsigned char *data, size_t &current_prt, size_t length)
{
    u4 value = 0;
    if (current_prt <= length - 4)
    {
        value += data[current_prt++] << 24;
        value += data[current_prt++] << 16;
        value += data[current_prt++] << 8;
        value += data[current_prt++];
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