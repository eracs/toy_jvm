#ifndef TOY_JVM_SOURCEFILE_ATTRIBUTE_H__
#define TOY_JVM_SOURCEFILE_ATTRIBUTE_H__

#include "Attribute_Info.h"

class SourceFile_attribute : Attribute_Info
{
private:
    std::string sourceFile;

public:
    SourceFile_attribute(std::string attributeName, u4 attributeLength, std::string sourceFile);
};

#endif // TOY_JVM_SOURCEFILE_ATTRIBUTE_H__