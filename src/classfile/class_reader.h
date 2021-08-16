#ifndef TOY_JVM_CLASS_READER_H
#define TOY_JVM_CLASS_READER_H

using u1 = unsigned char;
using u2 = unsigned short;
using u4 = unsigned int;

//read the next u1, failed when status is 0
u1 readNextU1(const unsigned char *data, size_t &current_ptr, const size_t &length, int &status);
//read the next u2, failed when status is 0
u2 readNextU2(const unsigned char *data, size_t &current_prt, const size_t &length, int &status);
//read the next u4, failed when status is 0
u4 readNextU4(const unsigned char *data, size_t &current_prt, const size_t &length, int &status);

#endif //TOY_JVM_CLASS_READER_H
