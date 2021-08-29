#ifndef TOY_JVM_EXCEPTIONS_ATTRIBUTE_H__
#define TOY_JVM_EXCEPTIONS_ATTRIBUTE_H__

#include "Attribute_Info.h"
#include <vector>

class Exceptions_attribute : public Attribute_Info
{
private:
    u2 number_of_exceptions;
    std::vector<u2> exception_index_tables;

public:
    Exceptions_attribute(std::string attributeName, u4 attributeLength, u2 numberOfExceptions, std::vector<u2> exceptionIndexTables);
};

#endif // TOY_JVM_EXCEPTIONS_ATTRIBUTE_H__