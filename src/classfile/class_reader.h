#ifndef TOY_JVM_CLASS_READER_H
#define TOY_JVM_CLASS_READER_H

using u1 = unsigned char;
using u2 = unsigned short;
using u4 = unsigned int;

u1 readNextU1(unsigned char *data, size_t &current_prt, size_t length);

u2 readNextU2(unsigned char *data, size_t &current_prt, size_t length);

u4 readNextU4(unsigned char *data, size_t &current_prt, size_t length);

#endif //TOY_JVM_CLASS_READER_H
