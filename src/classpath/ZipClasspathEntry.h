#ifndef TOY_JVM_ZIPCLASSPATHENTRY_H
#define TOY_JVM_ZIPCLASSPATHENTRY_H

#include "ClasspathEntry.h"

class ZipClasspathEntry : public ClasspathEntry {
private:
    std::string zipPath;
public:
    ZipClasspathEntry() = delete;

    ZipClasspathEntry(const ZipClasspathEntry &) = delete;

    ZipClasspathEntry(std::string zipPath);

    virtual ~ZipClasspathEntry();

    unsigned char *readClass(const std::string &className, size_t &length) const override;
};


#endif //TOY_JVM_ZIPCLASSPATHENTRY_H
