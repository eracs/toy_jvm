#ifndef TOY_JVM_CLASSFILE_H
#define TOY_JVM_CLASSFILE_H

#include "constant_pool/ConstantPool.h"
#include "Member_Info.h"

class ClassFile
{
private:
    u4 magicNumber;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    ConstantPool *constantPool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    std::vector<u2> interfaces;
    u2 fields_count;
    std::vector<std::shared_ptr<Member_Info>> fields;
    u2 methods_count;
    std::vector<std::shared_ptr<Member_Info>> methods;
    u2 attributes_count;
    std::vector<std::shared_ptr<Attribute_Info>> attributes;

public:
    ClassFile() = delete;

    //class file is broken when status is 0
    ClassFile(const unsigned char *data, const size_t &dataSize, int &status);

    u4 getMagicNumber() const;

    u2 getMinorVersion() const;

    u2 getMajorVersion() const;

    u2 getConstantPoolCount() const;

    ConstantPool *getConstantPool() const;

    virtual ~ClassFile();
};

#endif //TOY_JVM_CLASSFILE_H
