#include "classpath_entry.h"
#include "../file_reader/file_reader.h"
#include "../utils/string_utils.h"
#include "spdlog/spdlog.h"
using namespace std;
using namespace string_util;

using uint8 = unsigned char;

Zip_Classpath_Entry::Zip_Classpath_Entry(const std::string &path)
{
    this->zipPath = path;
}

Zip_Classpath_Entry::~Zip_Classpath_Entry()
{
}

uint8 *Zip_Classpath_Entry::readClass(const std::string &className, size_t &length) const
{
    auto logger = spdlog::get("Logger");
    logger->debug("ZipEntry start readClass, className={0} ", className);

    string classFilePath(className);
    auto entryName = replace_all(classFilePath, get_dot_separator(), get_path_separator());
    entryName = entryName + ".class";

    auto data = readZipEntry(this->zipPath, entryName, length);

    logger->debug("ZipEntry finish readClass, className={0}, filePath={1}, entryName={2}, dataSize={3}", className, this->zipPath, entryName, length);
    if (length == 0)
    {
        free(data);
        return nullptr;
    }
    return data;
}
