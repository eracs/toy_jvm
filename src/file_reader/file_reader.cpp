#include "file_reader.h"
#include <fstream>
extern "C"
{
#include "kubazip/zip/zip.h"
}

using namespace std;
using uint8 = unsigned char;

uint8 *readZipEntry(const char *fileName, const char *entryName, size_t &dataSize)
{
    uint8 *buf;
    size_t bufsize;
    struct zip_t *zip = zip_open(fileName, 0, 'r');
    {
        zip_entry_open(zip, entryName);
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

uint8 *readFileEntry(const char *fileName, size_t &dataSize)
{
    size_t size;
    char *buffer;
    ifstream filestr(fileName, ios::binary);
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

// kubazip demo
// size_t length;
// auto buf = readZipEntry("./foo.zip", "foo-1.txt", length);

// std::cout << length << std::endl;
// for (int i = 0; i < length; i++)
// {
//     std::cout << buf[i] - 0 << buf[i] << std::endl;
// }
// free(buf);