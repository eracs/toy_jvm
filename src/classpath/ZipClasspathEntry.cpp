#include <utility>

#include "ZipClasspathEntry.h"
#include "../file_reader/file_reader.h"
#include "../utils/string_utils.h"
#include "spdlog/spdlog.h"

using namespace std;
using namespace string_util;

ZipClasspathEntry::ZipClasspathEntry(std::string zipPath) : zipPath(std::move(zipPath))
{
}

ZipClasspathEntry::~ZipClasspathEntry()
{
}

uint8 *ZipClasspathEntry::readClass(const std::string &className, size_t &length) const
{
    auto logger = spdlog::get("Logger");
    logger->debug("From zip readClass, className={0}, path={1} ", className, this->zipPath);

    //将class名称转换成文件名
    string classFilePath(className);
    auto entryName = replace_all(classFilePath, get_dot_separator(), get_path_separator());
    entryName = entryName + get_class_file_ext();

    auto data = readZipEntry(this->zipPath, entryName, length);

    if (length == 0)
    {
        free(data);
        return nullptr;
    }

    logger->debug("ReadClass finished, className={0}, path={1},  dataSize={2}", className,
                  this->zipPath, length);
    return data;
}
