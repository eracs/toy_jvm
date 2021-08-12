#include "ClassFileReader.h"
#include "../utils/string_utils.h"
#include "../file_reader/file_reader.h"
#include "spdlog/spdlog.h"

using namespace string_util;
using namespace std;

void addChildPackages(const std::string &path, std::vector<std::unique_ptr<ClasspathEntry>> &container)
{
    auto logger = spdlog::get("Logger");
    unordered_map<string, string> childFiles;
    vector<string> childDirs;
    listDirFiles(path, childFiles, childDirs);
    for (auto item : childFiles)
    {
        if (item.second == "jar" || item.second == "zip")
        {
            string absPath = path + "/" + item.first;
            container.push_back(make_unique<ZipClasspathEntry>(absPath));
            logger->debug("ClassPath: add jar {0} ", absPath);
        }
    }
}

bool ClassFileReader::init(const std::string &jrePath, const std::string &classpath)
{
    auto logger = spdlog::get("Logger");
    auto jreParams = split(jrePath, get_param_separator());
    if (jreParams.size() == 0)
    {
        return false;
    }
    auto jrepath = jreParams[0];

    //启动类来自于%jre%/lib中的所有jar
    auto bootpath = jrepath + "/lib";
    logger->debug("ClassPath: bootpath is {0} ", bootpath);
    addChildPackages(bootpath, ClassFileReader::bootEntries);
    //拓展类来自于%jre%/lib/ext中的所有jar
    auto extpath = jrepath + "/lib/ext";
    logger->debug("ClassPath: extpath is {0} ", extpath);
    addChildPackages(extpath, ClassFileReader::extEntries);

    auto cpParams = split(classpath, get_param_separator());
    for (auto &path : cpParams)
    {
        logger->debug("ClassPath: start add classpath {0} ", path);
        if (endsWith(path, "*"))
        {
            auto realPath = path.substr(0, path.size() - 2);
            addChildPackages(realPath, ClassFileReader::userEntries);
        }
        else if (endsWith(path, ".zip") || endsWith(path, ".jar"))
        {
            logger->debug("ClassPath: add jar/zip {0} ", path);
            ClassFileReader::userEntries.push_back(make_unique<ZipClasspathEntry>(path));
        }
        else
        {
            if (endsWith(path, "/") || endsWith(path, "\\"))
            {
                auto realPath = path.substr(0, path.size() - 1);
                ClassFileReader::userEntries.push_back(make_unique<DirClasspathEntry>(realPath));
                addChildPackages(realPath, ClassFileReader::userEntries);
                logger->debug("ClassPath: add dir {0} ", realPath);
            }
            else
            {
                ClassFileReader::userEntries.push_back(make_unique<DirClasspathEntry>(path));
                addChildPackages(path, ClassFileReader::userEntries);
                logger->debug("ClassPath: add dir {0} ", path);
            }
        }
        logger->debug("ClassPath: finish add classpath {0} ", path);
    }
    logger->debug("Classpath prepared, boot entry size={0}, ext entry size={1}, user entry size={2}", ClassFileReader::bootEntries.size(), ClassFileReader::extEntries.size(), ClassFileReader::userEntries.size());

    return true;
}

uint8 *ClassFileReader::readClass(const std::string &className, size_t &length)
{
    uint8 *data = nullptr;
    if (ClassFileReader::fileReadHistory.find(className) != ClassFileReader::fileReadHistory.end())
    {
        auto p = ClassFileReader::fileReadHistory[className];
        if (p == 0)
        {
            for (auto &entry : ClassFileReader::bootEntries)
            {
                data = entry->readClass(className, length);
                if (length > 0)
                {
                    break;
                }
            }
        }
        else if (p == 1)
        {
            for (auto &entry : ClassFileReader::extEntries)
            {
                data = entry->readClass(className, length);
                if (length > 0)
                {
                    break;
                }
            }
        }
        else
        {
            for (auto &entry : ClassFileReader::userEntries)
            {
                data = entry->readClass(className, length);
                if (length > 0)
                {
                    break;
                }
            }
        }
        return data;
    }

    for (auto &entry : ClassFileReader::bootEntries)
    {
        data = entry->readClass(className, length);
        if (length > 0)
        {
            ClassFileReader::fileReadHistory.insert(make_pair(className, 0));
            return data;
        }
    }
    for (auto &entry : ClassFileReader::extEntries)
    {
        data = entry->readClass(className, length);
        if (length > 0)
        {
            ClassFileReader::fileReadHistory.insert(make_pair(className, 1));
            return data;
        }
    }
    for (auto &entry : ClassFileReader::userEntries)
    {
        data = entry->readClass(className, length);
        if (length > 0)
        {
            ClassFileReader::fileReadHistory.insert(make_pair(className, 2));
            return data;
        }
    }

    return nullptr;
}
