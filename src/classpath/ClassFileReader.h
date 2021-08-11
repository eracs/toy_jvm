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

    static ClassFileReader *m_instance_ptr;

public:
    bool init(const std::string &jre, const std::string &cp);

    uint8 *readClass(const std::string &className, size_t &length);

    static auto *get_instance()
    {
        if (m_instance_ptr == nullptr)
        {
            m_instance_ptr = new ClassFileReader;
        }
        return m_instance_ptr;
    };
};

#endif //TOY_JVM_CLASSFILEREADER_H
