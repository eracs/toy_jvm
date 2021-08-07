#include "test.h"
#include "../start/start_args.h"
#include "../file_reader/zip_reader.h"

using namespace std;

void test_parse_start_args(int argc, char *argv[])
{
    auto args = parseArgs(argc, argv);
}

void test_search_zip_entry()
{

    // kubazip demo
    size_t length;
    auto buf = readZipEntry("./foo.zip", "foo-1.txt", length);

    std::cout << "length is " << length << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "Index=" << buf[i] - 0 << " Value=" << buf[i] << std::endl;
    }
    free(buf);
}