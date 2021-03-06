#include "Code_attribute.h"
#include "../class_reader.h"
#include "attribute_info_factory.h"

Exception_Table::Exception_Table(u2 start_pc, u2 end_pc, u2 handler_pc, u2 catch_type) : start_pc(start_pc), end_pc(end_pc), handler_pc(handler_pc), catch_type(catch_type) {}

u2 Exception_Table::getStartPc() const
{
    return start_pc;
}

u2 Exception_Table::getEndPc() const
{
    return end_pc;
}

u2 Exception_Table::getHandlerPc() const
{
    return handler_pc;
}

u2 Exception_Table::getCatchType() const
{
    return catch_type;
}

Code_attribute::Code_attribute(std::string attributeName, u4 attributeLength, const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, std::shared_ptr<ConstantPool> constantPool) : Attribute_Info(attributeName, attributeLength)
{

    u4 end = current_ptr + attributeLength;

    max_stack = readNextU2(data, current_ptr, dataSize, status);

    max_locals = readNextU2(data, current_ptr, dataSize, status);

    code_length = readNextU4(data, current_ptr, dataSize, status);

    u4 i = 0;
    while (i < code_length && status)
    {
        code.emplace_back(readNextU1(data, current_ptr, dataSize, status));
        i++;
    }

    exception_table_length = readNextU2(data, current_ptr, dataSize, status);

    i = 0;
    while (i < code_length && status)
    {
        u2 start_pc = readNextU2(data, current_ptr, dataSize, status);
        u2 end_pc = readNextU2(data, current_ptr, dataSize, status);
        u2 handler_pc = readNextU2(data, current_ptr, dataSize, status);
        u2 catch_type = readNextU2(data, current_ptr, dataSize, status);

        exception_table.emplace_back(std::make_shared<Exception_Table>(start_pc, end_pc, handler_pc, catch_type));
    }

    attributes_count = readNextU2(data, current_ptr, dataSize, status);

    i = 0;
    while (status && i < attributes_count)
    {
        attributes.emplace_back(createAttributeInfo(data, current_ptr, dataSize, status, constantPool));
        i++;
    }
    if (current_ptr != end)
    {
        status = 0;
    }
}

u2 Code_attribute::getMaxStack() const
{
    return max_stack;
}

u2 Code_attribute::getMaxLocals() const
{
    return max_locals;
}

u4 Code_attribute::getCodeLength() const
{
    return code_length;
}

std::vector<u1> Code_attribute::getCodes() const
{
    return code;
}

u2 Code_attribute::getExceptionTableLength() const
{
    return exception_table_length;
}

std::vector<std::shared_ptr<Exception_Table>> Code_attribute::getExceptionTable() const
{
    return exception_table;
}

u2 Code_attribute::getAttributesCount() const
{
    return attributes_count;
}

std::vector<std::shared_ptr<Attribute_Info>> Code_attribute::getAttributes() const
{
    return attributes;
}