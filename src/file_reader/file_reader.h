#include <vector>
#include <string>
#include <unordered_map>

#ifndef TOY_JVM_ZIP_READER_H
#define TOY_JVM_ZIP_READER_H

unsigned char *readZipEntry(const char *fileName, const char *entryName, size_t &dataSize);

unsigned char *readFileEntry(const char *fileName, size_t &dataSize);

bool isDir(const char *path);

void listDirFiles(const char *path, std::unordered_map<std::string, std::string> &childFiles, std::vector<std::string> &childDirs);

#endif