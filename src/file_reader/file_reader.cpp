#include "file_reader.h"
#include <fstream>
#include <string>

extern "C"
{
#include "kubazip/zip/zip.h"
#include "tinydir.h"
}

using namespace std;
using uint8 = unsigned char;

uint8 *readZipEntry(std::string fileName, std::string entryName, size_t &dataSize)
{
    uint8 *buf;
    size_t bufsize;
    struct zip_t *zip = zip_open(fileName.c_str(), 0, 'r');
    {
        zip_entry_open(zip, entryName.c_str());
        {
            bufsize = zip_entry_size(zip);
            buf = static_cast<unsigned char *>(calloc(sizeof(unsigned char), bufsize));

            zip_entry_noallocread(zip, (void *)buf, bufsize);
        }
        zip_entry_close(zip);
    }
    zip_close(zip);
    dataSize = bufsize;
    return buf;
}

uint8 *readFileEntry(std::string fileName, size_t &dataSize)
{
    size_t size;
    char *buffer;
    ifstream filestr(fileName.c_str(), ios::binary);
    if (!filestr)
    {
        dataSize = 0;
        return nullptr;
    }
    auto pbuf = filestr.rdbuf();
    size = pbuf->pubseekoff(0, ios::end, ios::in);
    pbuf->pubseekpos(0, ios::in);
    buffer = new char[size];
    pbuf->sgetn(buffer, size);
    dataSize = size;
    auto *result = new uint8[size];
    for (size_t i = 0; i <= size; i++)
    {
        result[i] = buffer[i];
    }
    filestr.close();
    free(buffer);
    return result;
}

bool isDir(std::string path)
{
    tinydir_file file;
    if (tinydir_file_open(&file, path.c_str()) < 0)
    {
        return false;
    }

    return file.is_dir;
}

void listDirFiles(std::string path, unordered_map<string, string> &childFiles, vector<string> &childDirs)
{
    tinydir_dir dir;
    if (tinydir_open(&dir, path.c_str()) < 0)
    {
        return;
    }
    while (dir.has_next)
    {
        tinydir_file file;
        tinydir_readfile(&dir, &file);
        string fileName = file.name;
        if (file.is_dir)
        {
            if (fileName == "." || fileName == "..")
            {
            }
            else
            {
                childDirs.push_back(fileName);
            }
        }
        else
        {
            string fileExt = file.extension;
            childFiles.insert({fileName, fileExt});
        }
        tinydir_next(&dir);
    }
    tinydir_close(&dir);
}