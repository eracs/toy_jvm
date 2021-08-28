#ifndef TOY_JVM_CODE_ATTRIBUTE_H
#define TOY_JVM_CODE_ATTRIBUTE_H

#include "Attribute_Info.h"
#include <vector>
#include <memory>
#include "../constant_pool/ConstantPool.h"

class Exception_Table
{
private:
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;

public:
    Exception_Table() = delete;

    Exception_Table(u2 start_pc, u2 end_pc, u2 handler_pc, u2 catch_type);
};

class Code_attribute : public Attribute_Info
{
private:
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    std::vector<u1> code;
    u2 exception_table_length;
    std::vector<std::shared_ptr<Exception_Table>> exception_table;
    u2 attributes_count;
    std::vector<std::shared_ptr<Attribute_Info>> attributes;

public:
    Code_attribute() = delete;
    Code_attribute(std::string attributeName, u4 attributeLength, const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, std::shared_ptr<ConstantPool> contantPool);

    u2 getMaxStack() const;
    u2 getMaxLocals() const;
    u4 getCodeLength() const;
    std::vector<u1> getCodes() const;
    u2 getExceptionTableLength() const;
    std::vector<std::shared_ptr<Exception_Table>> getExceptionTable() const;
    u2 getAttributesCount() const;
    std::vector<std::shared_ptr<Attribute_Info>> getAttributes() const;
};

#endif