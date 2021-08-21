#include "Code_attribute.h"
#include "../class_reader.h"
#include "attribute_info_factory.h"

Exception_Table::Exception_Table(u2 start_pc, u2 end_pc, u2 handler_pc, u2 catch_type) : start_pc(start_pc), end_pc(end_pc), handler_pc(handler_pc), catch_type(catch_type) {}

Code_attribute::Code_attribute(std::string attributeName, u4 attributeLength, const unsigned char *data, size_t &current_ptr, const size_t &dataSize, int &status, ConstantPool *constantPool) : Attribute_Info(attributeName, attributeLength)
{

    u4 end = current_ptr + attributeLength;
    if (status)
    {
        max_stack = readNextU2(data, current_ptr, dataSize, status);
    }
    if (status)
    {
        max_locals = readNextU2(data, current_ptr, dataSize, status);
    }
    if (status)
    {
        code_length = readNextU4(data, current_ptr, dataSize, status);
    }
    u4 i = 0;
    while (i < code_length && status)
    {
        code.emplace_back(readNextU1(data, current_ptr, dataSize, status));
        i++;
    }

    if (status)
    {
        exception_table_length = readNextU2(data, current_ptr, dataSize, status);
    }
    i = 0;
    while (i < code_length && status)
    {
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;
        start_pc = readNextU2(data, current_ptr, dataSize, status);
        if (status)
        {
            end_pc = readNextU2(data, current_ptr, dataSize, status);
        }
        if (status)
        {
            handler_pc = readNextU2(data, current_ptr, dataSize, status);
        }
        if (status)
        {
            catch_type = readNextU2(data, current_ptr, dataSize, status);
        }
        if (status)
        {
            exception_table.emplace_back(std::make_shared<Exception_Table>(start_pc, end_pc, handler_pc, catch_type));
        }
    }
    if (status)
    {
        attributes_count = readNextU2(data, current_ptr, dataSize, status);
    }
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