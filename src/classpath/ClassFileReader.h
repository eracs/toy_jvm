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

    //init classpath
    bool init(const std::string &jrePath, const std::string &classpath);

    //read class binary content by classname
    uint8 *readClass(const std::string &className, size_t &length);

    //Singleton
    static ClassFileReader &get_instance()
    {
        static ClassFileReader m_pInstance;
        return m_pInstance;
    };
};

#endif //TOY_JVM_CLASSFILEREADER_H
