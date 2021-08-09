#include "classpath_entry.h"
#include "../file_reader/file_reader.h"
#include "../utils/string_utils.h"
using namespace std;
using namespace string_util;

using uint8 = unsigned char;

Zip_Classpath_Entry::Zip_Classpath_Entry(const std::string &path)
{
    this->absPath = path;
}

Zip_Classpath_Entry::~Zip_Classpath_Entry()
{
}

uint8 *Zip_Classpath_Entry::readClass(const std::string &className, size_t &length) const
{
    cout << "read class " << className << endl;
    string fileName(this->absPath);

    size_t dataSize = 0;
    string classFilePath = (className);

    auto entryName = replace_all(classFilePath, get_dot_separator(), get_path_separator());
    entryName = entryName + ".class";
    cout << "fileName is " << fileName << endl;
    cout << "EntryName is " << entryName << endl;
    auto data = readZipEntry(fileName.c_str(), entryName.c_str(), dataSize);
    length = dataSize;
    if (dataSize = 0)
    {
        return nullptr;
    }
    return data;
}
