#include <utility>

#include "DirClasspathEntry.h"
#include "../file_reader/file_reader.h"
#include "../utils/string_utils.h"
#include "spdlog/spdlog.h"

using namespace std;
using namespace string_util;

DirClasspathEntry::~DirClasspathEntry()
{
}

DirClasspathEntry::DirClasspathEntry(std::string dirPath) : dirPath(std::move(dirPath)) {}

uint8 *DirClasspathEntry::readClass(const std::string &className, size_t &length) const
{
    auto logger = spdlog::get("Logger");
    logger->debug("From dir readClass, className={0}, path={1}  ", className, this->dirPath);

    //将classname转换成文件路径
    string classFilePath(className);
    auto entryName = replace_all(classFilePath, get_dot_separator(), get_path_separator());
    entryName = entryName + get_class_file_ext();
    string fileName = this->dirPath + get_path_separator() + entryName;

    auto data = readFileEntry(fileName, length);

    if (length == 0)
    {
        return nullptr;
    }
    logger->debug("ReadClass finished, className={0}, path={1},  dataSize={2}", className,
                  this->dirPath, length);
    return data;
}
