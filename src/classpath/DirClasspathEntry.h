#ifndef TOY_JVM_DIRCLASSPATHENTRY_H
#define TOY_JVM_DIRCLASSPATHENTRY_H

#include "ClasspathEntry.h"

class DirClasspathEntry : public ClasspathEntry {
private:
    std::string dirPath;
public:
    DirClasspathEntry() = delete;

    DirClasspathEntry(const DirClasspathEntry &) = delete;

    DirClasspathEntry(std::string dirPath);

    virtual ~DirClasspathEntry();

    unsigned char *readClass(const std::string &className, size_t &length) const override;
};


#endif //TOY_JVM_DIRCLASSPATHENTRY_H
