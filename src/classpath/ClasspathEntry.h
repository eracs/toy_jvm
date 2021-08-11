#ifndef TOY_JVM_CLASSPATHENTRY_H
#define TOY_JVM_CLASSPATHENTRY_H

#include <string>

using uint8 = unsigned char;

class ClasspathEntry
{
public:
    virtual uint8 *readClass(const std::string &className, size_t &length) const = 0;
};

#endif //TOY_JVM_CLASSPATHENTRY_H
