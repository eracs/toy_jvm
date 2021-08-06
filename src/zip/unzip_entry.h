#include <string>

#ifndef TOY_JVM_UNZIP_ENTRY_H
#define TOY_JVM_UNZIP_ENTRY_H

unsigned char *readZipEntry(const char *fileName, const char *entryName, size_t &dataSize);

#endif