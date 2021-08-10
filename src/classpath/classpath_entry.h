#ifndef TOY_JVM_CLASSPATH_ENTRY_H
#define TOY_JVM_CLASSPATH_ENTRY_H

#include <string>

class Classpath_Entry
{
public:
    virtual unsigned char *readClass(const std::string &className, size_t &length) const = 0;
};

class Zip_Classpath_Entry : public Classpath_Entry
{
private:
    /* data */
    std::string zipPath;

public:
    Zip_Classpath_Entry() = delete;
    Zip_Classpath_Entry(const Zip_Classpath_Entry &) = delete;
    Zip_Classpath_Entry(const std::string &);
    ~Zip_Classpath_Entry();
    unsigned char *readClass(const std::string &className, size_t &length) const override;
};

class Dir_Classpath_Entry : public Classpath_Entry
{
private:
    /* data */
    std::string dirPath;

public:
    Dir_Classpath_Entry() = delete;
    Dir_Classpath_Entry(const Dir_Classpath_Entry &) = delete;
    Dir_Classpath_Entry(const std::string &);
    ~Dir_Classpath_Entry();
    unsigned char *readClass(const std::string &className, size_t &length) const override;
};

#endif