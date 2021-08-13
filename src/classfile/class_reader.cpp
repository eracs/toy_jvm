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
