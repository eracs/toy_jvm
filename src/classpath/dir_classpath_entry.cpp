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

    return nullptr;
}