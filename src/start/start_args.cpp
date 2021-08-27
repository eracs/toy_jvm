//
// Created by eracs on 2021/7/21.
//

#include "start_args.h"
#include <iostream>
#include <cstdlib>
#include "clara.hpp"
#include "../utils/string_utils.h"

using namespace std;
using namespace clara;

std ::string version = "0.0.1";

void showVersion()
{
    cout << "Toy JVM " << version << endl;
}

void showTitle()
{
    cout << "Toy Jvm written in c++, version " << version << endl;
    cout << endl;
    cout << "Project: https://github.com/eracs/toy_jvm" << endl;
}

void printHelpInfo(const std::string &left, const std::string &right)
{
    int remainSize = 40 - left.size();
    cout << left;
    if (remainSize > 0)
    {
        while (remainSize--)
        {
            cout << " ";
        }
    }
    cout << " " << right << endl;
}

std::shared_ptr<StartArgs> parseArgs(int argc, char *argv[])
{

    bool help = false;
    bool version = false;
    bool debug = false;
    std::string classpath;
    std::string jrepath;

    auto helpParse = Help(help);
    auto versionParse = Opt(version)["-v"]["-version"]["--version"]("Show the version.");

    auto pathParse = Opt(classpath, "CLASSPATH")["-cp"]["-classpath"]["--classpath"]("Set the classpath, default is current path") |
                     Opt(jrepath, "JAVA_RUNTIME")["-jre"]["--jre"]["--xjre"]("Set the jre path, could be JAVA_HOME/jre") |
                     Opt(debug)["-d"]["-debug"]["--log"]("Show the debug info.");
    std::shared_ptr<StartArgs> emptyPtr(nullptr);
    if (helpParse.parse(Args(argc, argv)))
    {
        if (help)
        {
            showTitle();
            for (auto v : helpParse.getHelpColumns())
            {
                printHelpInfo(v.left, v.right);
            }
            for (auto v : versionParse.getHelpColumns())
            {
                printHelpInfo(v.left, v.right);
            }

            for (auto v : pathParse.getHelpColumns())
            {
                printHelpInfo(v.left, v.right);
            }

            return emptyPtr;
        }
    }
    if (versionParse.parse(Args(argc, argv)))
    {
        if (version)
        {
            showVersion();
            return emptyPtr;
        }
    }

    if (pathParse.parse(Args(argc, argv)))
    {
    }
    else
    {
        classpath = ".";
        jrepath = "";
    }
    if (classpath == "")
    {
        classpath = ".";
    }
    if (jrepath == "")
    {
        auto jenv = getenv("JAVA_HOME");
        if (jenv == NULL)
        {
            cerr << "The jre path cannot be empty" << endl;
            return emptyPtr;
        }
        std::string javahome(jenv);
        if (javahome.empty())
        {
            cerr << "The jre path cannot be empty" << endl;
            return emptyPtr;
        }
        else
        {
            if (string_util::endsWith(javahome, "/") || string_util::endsWith(javahome, "\\"))
            {
                jrepath = javahome + "jre";
            }
            else
            {
                jrepath = javahome + "/jre";
            }
        }
    }

    return std::make_shared<StartArgs>(classpath, jrepath, debug);
}

StartArgs::StartArgs(std::string classpath, std::string jre, bool debug) : classpath(classpath), jre(jre), debug(debug) {}

const std::string &StartArgs::getClasspath() const
{
    return classpath;
}

const std::string &StartArgs::getJrePath() const
{
    return jre;
}

const bool StartArgs::isDebugMode() const
{
    return debug;
}