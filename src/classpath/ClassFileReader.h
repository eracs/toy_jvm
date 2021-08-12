#ifndef TOY_JVM_CLASSFILEREADER_H
#define TOY_JVM_CLASSFILEREADER_H

#include <unordered_map>
#include <vector>
#include <memory>

#include "ClasspathEntry.h"
#include "DirClasspathEntry.h"
#include "ZipClasspathEntry.h"

class ClassFileReader
{
private:
    ClassFileReader() = default;

    std::vector<std::unique_ptr<ClasspathEntry>> bootEntries;
    std::vector<std::unique_ptr<ClasspathEntry>> extEntries;
    std::vector<std::unique_ptr<ClasspathEntry>> userEntries;

    std::unordered_map<std::string, int> fileReadHistory;

public:
    ClassFileReader(const ClassFileReader &) = delete;

    ClassFileReader &operator=(const ClassFileReader &) = delete;

    //初始化，也是启动的时候调用
    bool init(const std::string &jrePath, const std::string &classpath);

    //从磁盘中根据classname读取字节码
    uint8 *readClass(const std::string &className, size_t &length);

    //单例模式
    static ClassFileReader &get_instance()
    {
        static ClassFileReader m_pInstance; //局部静态变量
        return m_pInstance;
    };
};

#endif //TOY_JVM_CLASSFILEREADER_H
