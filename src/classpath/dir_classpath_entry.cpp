#include "classpath_entry.h"
#include "../file_reader/file_reader.h"
#include "../utils/string_utils.h"
#include "spdlog/spdlog.h"
using namespace std;
using namespace string_util;

using uint8 = unsigned char;

Dir_Classpath_Entry::Dir_Classpath_Entry(const std::string &path)
{
    this->dirPath = path;
}

Dir_Classpath_Entry::~Dir_Classpath_Entry()
{
}

uint8 *Dir_Classpath_Entry::readClass(const std::string &className, size_t &length) const
{
    auto logger = spdlog::get("Logger");
    logger->debug("DirEntry start readClass, className={0} ", className);

    string classFilePath(className);
    auto entryName = replace_all(classFilePath, get_dot_separator(), get_path_separator());
    entryName = entryName + get_class_file_ext();
    string fileName = this->dirPath + get_path_separator() + entryName;
    auto data = readFileEntry(fileName, length);
    logger->debug("DirEntry finish readClass, className={0}, dirPath={1},filePath={2}, entryName={3}, dataSize={4}", className, this->dirPath, fileName, entryName, length);
    if (length == 0)
    {
        return nullptr;
    }
    return data;
}