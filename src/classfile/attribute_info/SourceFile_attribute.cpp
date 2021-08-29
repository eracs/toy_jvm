#include "SourceFile_attribute.h"

SourceFile_attribute::SourceFile_attribute(std::string attributeName, u4 attributeLength, std::string sourceFile) : Attribute_Info(attributeName, attributeLength), sourceFile(sourceFile) {}
