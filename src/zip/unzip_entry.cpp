#include "unzip_entry.h"

extern "C"
{
#include "kubazip/zip/zip.h"
}

using uint8 = unsigned char;

uint8 *readZipEntry(const char *fileName, const char *entryName)
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
    return buf;
}

size_t strlenZipEntry(uint8 *data)
{
    return strlen(reinterpret_cast<const char *>(data));
}
