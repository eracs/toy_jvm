#ifndef TOY_JVM_ZIP_READER_H
#define TOY_JVM_ZIP_READER_H

#include <vector>
#include <string>
#include <unordered_map>

using uint8 = unsigned char;

//读取压缩包中某个文件的内容，dataSize=0即为文件不存在
uint8 *readZipEntry(const std::string fileName, std::string entryName, size_t &dataSize);

//读取文件的内容到内存,根据C++规范,char为机器字节大小（8位），dataSize=0即为文件不存在
uint8 *readFileEntry(const std::string fileName, size_t &dataSize);

//判断某个路径是否为文件夹，不能带有末尾的"/"或者"\"
bool isDir(const std::string &path);

//将某个路径下的所有子文件/子文件夹解析出来，map中的key为文件名，value为文件名的拓展名
void listDirFiles(const std::string &path, std::unordered_map<std::string, std::string> &childFiles, std::vector<std::string> &childDirs);

//根据路径判断文件是否存储
bool fileExist(const std::string &path);
#endif