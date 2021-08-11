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

unsigned char *ZipClasspathEntry::readClass(const std::string &className, size_t &length) const
{
    auto logger = spdlog::get("Logger");
    logger->debug("ZipEntry start readClass, className={0} ", className);

    string classFilePath(className);
    auto entryName = replace_all(classFilePath, get_dot_separator(), get_path_separator());
    entryName = entryName + get_class_file_ext();

    auto data = readZipEntry(this->zipPath, entryName, length);

    logger->debug("ZipEntry finish readClass, className={0}, filePath={1}, entryName={2}, dataSize={3}", className,
                  this->zipPath, entryName, length);
    if (length == 0)
    {
        free(data);
        return nullptr;
    }
    return data;
}
