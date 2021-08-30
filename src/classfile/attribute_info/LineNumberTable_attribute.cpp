#include "LineNumberTable_attribute.h"
LineNumberTableItem::LineNumberTableItem(u2 start_pc, u2 line_number) : start_pc(start_pc), line_number(line_number) {}

u2 LineNumberTableItem::getStartPc() const
{
    return start_pc;
}

u2 LineNumberTableItem::getLineNumber() const
{
    return line_number;
}

LineNumberTable_attribute::LineNumberTable_attribute(std::string attributeName, u4 attributeLength, u2 lineNumberTableLength, std::vector<LineNumberTableItem> lineNumberTable)
    : Attribute_Info(attributeName, attributeLength), line_number_table_length(line_number_table_length), line_number_table(lineNumberTable)
{
}

u2 LineNumberTable_attribute::getLineNumberTableLength() const
{
    return line_number_table_length;
}

std::vector<LineNumberTableItem> LineNumberTable_attribute::getLineNumberTable() const
{
    return line_number_table;
}
