#include <string>

#ifndef TOY_JVM_ZIP_READER_H
#define TOY_JVM_ZIP_READER_H

unsigned char *readZipEntry(const char *fileName, const char *entryName, size_t &dataSize);

unsigned char *readFileEntry(const char *fileName, size_t &dataSize);
#endif