//
// Created by eracs on 2021/7/21.
//

#include "start_args.h"
#include <cstdlib>
#include <iostream>
#include "../clara/clara.hpp"
using namespace std;
using namespace clara;

std ::string version = "0.0.1";

void showVersion()
{
    cout << "toy_jvm_" << version << endl;
}

void showTitle()
{
    showVersion();
    cout << "Toy Jvm written in c++" << endl;
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
    std::string jre;
    std::string args;
    auto helpParse = Help(help);
    auto versionParse = Opt(version)["-v"]["--version"]("Show the version.");
    auto classpathParse = Opt(classpath, "CLASSPATH")["-cp"]["--classpath"]("Set the classpath");
    auto jreParse = Opt(jre, "JAVA_HOME/jre")["-jre"]["--xjre"]("Set the jre path,default is %JAVA_HOME%/jre");
    auto argsParse = Opt(args, "args")["-args"]["--command"]("The command is forwarded to the program(public static void main(String[] args))");
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
            for (auto v : classpathParse.getHelpColumns())
            {
                printHelpInfo(v.left, v.right);
            }
            for (auto v : jreParse.getHelpColumns())
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

    if (classpathParse.parse(Args(argc, argv)))
    {
    }
    else
    {
        classpath = "";
    }
    if (jreParse.parse(Args(argc, argv)))
    {
    }
    else
    {
        auto javaHome = getenv("JAVA_HOME");
        if (javaHome)
        {
            jre += javaHome;
            jre += "/lib";
        }
        else
        {
            jre = "";
        }
    }
    if (classpath == "")
    {
        cout << "The classpath cannot be empty" << endl;
        return nullptr;
    }
    if (jre == "")
    {
        cout << "The jre path cannot be empty" << endl;
        return nullptr;
    }
    if (argsParse.parse(Args(argc, argv)))
    {
    }
    else
    {
        args = "";
    }
    startArgs->classpath = classpath;
    startArgs->jre = jre;
    startArgs->command = args;
    return startArgs;
}
