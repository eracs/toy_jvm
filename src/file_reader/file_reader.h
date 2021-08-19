#ifndef TOY_JVM_ZIP_READER_H
#define TOY_JVM_ZIP_READER_H

#include <vector>
#include <string>
#include <unordered_map>

using uint8 = unsigned char;
//读取zip中某个文件的二进制表示
uint8 *readZipEntry(const std::string fileName, std::string entryName, size_t &dataSize);
//读取文件的二进制表示
uint8 *readFileEntry(const std::string fileName, size_t &dataSize);
//路径是否为目录
bool isDir(const std::string &path);
//获取路径下面的所有文件
void listDirFiles(const std::string &path, std::unordered_map<std::string, std::string> &childFiles, std::vector<std::string> &childDirs);
//文件路径是否存在
bool fileExist(const std::string &path);
#endif