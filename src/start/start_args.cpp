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

StartArgs *parseArgs(int argc, char *argv[])
{

    bool help = false;
    bool version = false;
    std::string classpath;
    std::string jrepath;
    std::string args;
    auto helpParse = Help(help);
    auto versionParse = Opt(version)["-v"]["-version"]["--version"]("Show the version.");
    auto pathParse = Opt(classpath, "CLASSPATH")["-cp"]["-classpath"]["--classpath"]("Set the classpath, default is current path") |
                     Opt(jrepath, "JAVA_RUNTIME")["-jre"]["--jre"]["--xjre"]("Set the jre path, could be JAVA_HOME/jre");
    auto argsParse = Opt(args, "args")["-args"]["--args"]["--command"]("The command is forwarded to the program(public static void main(String[] args))");
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

            for (auto v : argsParse.getHelpColumns())
            {
                printHelpInfo(v.left, v.right);
            }
            return nullptr;
        }
    }
    if (versionParse.parse(Args(argc, argv)))
    {
        if (version)
        {
            showVersion();
            return nullptr;
        }
    }
    auto startArgs = new StartArgs;

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
        std::string javahome(getenv("JAVA_HOME"));
        if (javahome.empty())
        {
            cerr << "The jre path cannot be empty" << endl;
            return nullptr;
        }
        else
        {
            if (string_util::endsWith(javahome, "/") || string_util::endsWith(javahome, "\\"))
            {
                jrepath = javahome + "jre/";
            }
            else
            {
                jrepath = javahome + "/jre/";
            }
        }
    }
    if (argsParse.parse(Args(argc, argv)))
    {
    }
    else
    {
        args = "";
    }
    startArgs->classpath = classpath;
    startArgs->jre = jrepath;
    startArgs->command = args;
    return startArgs;
}
