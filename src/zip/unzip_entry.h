#include <string>

struct ZipData
{
    size_t length;
    unsigned char *data;
};

unsigned char *readZipEntry(const char *fileName, const char *entryName, size_t &dataSize);

