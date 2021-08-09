#include "test.h"
#include "../start/start_args.h"
#include "../file_reader/file_reader.h"

using namespace std;

void run_test(int argc, char *argv[])
{
    // test_parse_start_args(argc, argv);
    // cout << "test_read_zip" << endl;
    // test_search_zip_entry();
    // cout << "test_read_file" << endl;
    // test_search_file_entry();
    test_list_file(argc, argv);
}

void test_list_file(int argc, char *argv[])
{
    auto args = parseArgs(argc, argv);
    if (!args)
    {
        cout << "Failed to parse args" << endl;
        return;
    }
    vector<string> dirs;
    unordered_map<string, string> files;

    listDirFiles(args->jre.c_str(), files, dirs);
    cout << "dirs:" << endl;
    for (const auto &item : dirs)
    {
        cout << item << endl;
    }
    cout << "files:" << endl;
    for (const auto &item : files)
    {
        cout << "FileName:" << item.first << " FileExt:" << item.second << endl;
    }
}

void test_parse_start_args(int argc, char *argv[])
{
    auto args = parseArgs(argc, argv);
    if (args)
    {
        cout << args->jre << endl;
        size_t length;
        string fileName = args->jre + "/foo.zip";
        auto buf = readZipEntry(fileName.c_str(), "foo-1.txt", length);

        std::cout << "length is " << length << std::endl;
        for (int i = 0; i < length; i++)
        {
            std::cout << "index=" << i << " ASCII=" << buf[i] - 0 << " Value=" << buf[i] << std::endl;
        }
        free(buf);
    }
    else
    {
        cout << "env error" << endl;
    }
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