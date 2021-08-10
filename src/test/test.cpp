#include "test.h"
#include "../start/start_args.h"
#include "../file_reader/file_reader.h"
#include "../utils/string_utils.h"
#include "../classpath/classpath_entry.h"
#include "spdlog/spdlog.h"

using namespace std;

void run_test(int argc, char *argv[])
{
    // auto javahome = getenv("JAVA_HOME");
    // spdlog::info("JAVA_HOME is {0}", javahome);
    // test_parse_start_args(argc, argv);
    // cout << "test_read_zip" << endl;
    // test_search_zip_entry();
    // cout << "test_read_file" << endl;
    // test_search_file_entry();
    // test_list_file(argc, argv);
    // auto s = string_util::get_param_separator();
    // std::cout << s << endl;
    spdlog::info("File exist {0}",fileExist("./foo-1-backup.txt"));
    spdlog::info("Dir exist {0}",isDir("."));
}

void test_list_file(int argc, char *argv[])
{
    auto args = parseArgs(argc, argv);
    if (!args)
    {
        spdlog::get("Logger")->error("Failed to parse args");
        return;
    }
    vector<string> dirs;
    unordered_map<string, string> files;

    listDirFiles(args->jre, files, dirs);
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
        string fileName = args->jre + "test.zip";
        spdlog::info("start test zip entry");
        Zip_Classpath_Entry zip_entry(fileName);
        auto buf = zip_entry.readClass("test.foo", length);
        // auto buf = readZipEntry(fileName.c_str(), "test/foo.class", length);
        std::cout << "length is " << length << std::endl;
        for (int i = 0; i < length; i++)
        {
            std::cout << "index=" << i << " ASCII=" << buf[i] - 0 << " Value=" << buf[i] << std::endl;
        }
        free(buf);
        spdlog::info("start test dir entry");
        string dirPath = args->jre + "childDir";
        Dir_Classpath_Entry dir_entry(dirPath);
        size_t dataSize;
        auto data = dir_entry.readClass("toy.Main", dataSize);
        spdlog::info("the entry data size={0}", dataSize);
        for (int i = 0; i < dataSize; i++)
        {
            std::cout << "index=" << i << " ASCII=" << data[i] - 0 << " Value=" << data[i] << std::endl;
        }
        free(data);
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