#ifndef TOY_JVM_LINENUMBERTABLE_ATTRIBUTE_H__
#define TOY_JVM_LINENUMBERTABLE_ATTRIBUTE_H__

#include "Attribute_Info.h"
#include <vector>

class LineNumberTableItem
{
private:
    u2 start_pc;
    u2 line_number;

public:
    LineNumberTableItem(u2 start_pc, u2 line_number);
    u2 getStartPc() const;
    u2 getLineNumber() const;
};

class LineNumberTable_attribute : public Attribute_Info
{
private:
    u2 line_number_table_length;
    std::vector<LineNumberTableItem> line_number_table;

public:
    LineNumberTable_attribute(std::string attributeName, u4 attributeLength, u2 lineNumberTableLength, std::vector<LineNumberTableItem> lineNumberTable);

    u2 getLineNumberTableLength() const;
    std::vector<LineNumberTableItem> getLineNumberTable() const;
};

#endif // __LINENUMBERTABLE_ATTRIBUTE_H__