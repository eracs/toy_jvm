#include "Exceptions_attribute.h"

Exceptions_attribute::Exceptions_attribute(std::string attributeName, u4 attributeLength, u2 numberOfExceptions, std::vector<u2> exceptionIndexTables) : Attribute_Info(attributeName, attributeLength), number_of_exceptions(numberOfExceptions), exception_index_tables(exceptionIndexTables) {}
