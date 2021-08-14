#ifndef TOY_JVM_CLASSFILE_H
#define TOY_JVM_CLASSFILE_H

#include "constant_pool/ConstantPool.h"

class ClassFile
{
private:
    u4 magicNumber;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    ConstantPool *constantPool;

public:
    ClassFile() = delete;

    ClassFile(const unsigned char *data, const size_t &dataSize, int &status);

    u4 getMagicNumber() const;

    u2 getMinorVersion() const;

    u2 getMajorVersion() const;

    u2 getConstantPoolCount() const;

    ConstantPool *getConstantPool() const;

    virtual ~ClassFile();
};

#endif //TOY_JVM_CLASSFILE_H
