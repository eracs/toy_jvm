#ifndef TOY_JVM_ZIP_READER_H
#define TOY_JVM_ZIP_READER_H

#include <vector>
#include <string>
#include <unordered_map>

using uint8 = unsigned char;

uint8 *readZipEntry(const std::string fileName, std::string entryName, size_t &dataSize);

uint8 *readFileEntry(const std::string fileName, size_t &dataSize);

bool isDir(const std::string &path);

void listDirFiles(const std::string &path, std::unordered_map<std::string, std::string> &childFiles, std::vector<std::string> &childDirs);

bool fileExist(const std::string &path);
#endif