#include "test.h"
#include "../start/start_args.h"
#include "../file_reader/zip_reader.h"

using namespace std;

void run_test(int argc, char *argv[])
{
    test_parse_start_args(argc, argv);
    cout << "test_read_zip" << endl;
    test_search_zip_entry();
    cout << "test_read_file" << endl;
    test_search_file_entry();
}

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
        std::cout << "index=" << i << " ASCII=" << buf[i] - 0 << " Value=" << buf[i] << std::endl;
    }
    free(buf);
}

void test_search_file_entry()
{

    // kubazip demo
    size_t length;
    auto buf = readFileEntry("./foo-1.txt", length);

    std::cout << "length is " << length << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << "index=" << i << " ASCII=" << buf[i] - 0 << " Value=" << buf[i] << std::endl;
    }
    free(buf);
}