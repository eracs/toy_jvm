#include <iostream>

#ifndef TOY_JVM_CLASSPATH_ENTRY
#define TOY_JVM_CLASSPATH_ENTRY
class Classpath_Entry
{
public:
    virtual unsigned char *readClass(const std::string &className, int &length) const;
};

class Zip_Classpath_Entry : public Classpath_Entry
{
public:
    const std::string absPath;
    unsigned char *readClass(const std::string &className, int &length) const override
    {
        return nullptr;
    }
};

#endif