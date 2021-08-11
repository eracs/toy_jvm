#include "ClassFileReader.h"
#include "../utils/string_utils.h"
#include "../file_reader/file_reader.h"

using namespace string_util;
using namespace std;

void addChildPackages(const std::string &path, std::vector<std::unique_ptr<ClasspathEntry>> &container)
{
    unordered_map<string, string> childFiles;
    vector<string> childDirs;
    listDirFiles(path, childFiles, childDirs);
    for (auto item : childFiles)
    {
        if (item.second == "jar")
        {
            container.push_back(make_unique<ZipClasspathEntry>(item.first));
        }
    }
}

bool ClassFileReader::init(const std::string &jrePath, const std::string &classpath)
{
    auto jreParams = split(jrePath, get_param_separator());
    if (jreParams.size() == 0)
    {
        return false;
    }
    auto jrepath = jreParams[0];

    //启动类来自于%jre%/lib中的所有jar
    auto bootpath = jrepath + "/lib";
    addChildPackages(bootpath, ClassFileReader::bootEntries);
    //拓展类来自于%jre%/lib/ext中的所有jar
    auto extpath = jrepath + "/lib/ext";
    addChildPackages(extpath, ClassFileReader::extEntries);

    auto cpParams = split(classpath, get_param_separator());
    for (auto &path : cpParams)
    {
        if (endsWith(path, "*"))
        {
            auto realPath = path.substr(0, path.size() - 2);
            addChildPackages(realPath, ClassFileReader::userEntries);
        }
        else if (endsWith(path, ".zip") || endsWith(path, ".jar"))
        {
            ClassFileReader::userEntries.push_back(make_unique<ZipClasspathEntry>(path));
        }
        else
        {
            if (endsWith(path, "/") || endsWith(path, "\\"))
            {
                ClassFileReader::userEntries.push_back(make_unique<ZipClasspathEntry>(path.substr(0, path.size() - 1)));
            }
            else
            {
                ClassFileReader::userEntries.push_back(make_unique<ZipClasspathEntry>(path));
            }
        }
    }
    return true;
}

uint8 *ClassFileReader::readClass(const std::string &className, size_t &length)
{
    return nullptr;
}
