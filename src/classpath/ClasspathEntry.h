#ifndef TOY_JVM_CLASSPATHENTRY_H
#define TOY_JVM_CLASSPATHENTRY_H

#include <string>

class ClasspathEntry {
public:
    virtual unsigned char *readClass(const std::string &className, size_t &length) const = 0;
};


#endif //TOY_JVM_CLASSPATHENTRY_H
