//
// Created by eracs on 2021/7/21.
//

#include "start_args.h"

using namespace std;

StartArgs *parseArgs(int argc, char *argv[])
{
    auto startArgs = new StartArgs;
    startArgs->helpFlag = false;
    startArgs->versionFlag = false;
    for (int i = 1; i < argc;)
    {
        string arg = argv[i];
        if (arg == "-?" || arg == "-help")
        {
            startArgs->helpFlag = true;
        }
        else if (arg == "--version" || arg == "-v")
        {
            startArgs->versionFlag = true;
        }
        else if (arg == "-cp" || arg == "-classpath")
        {
            startArgs->classpath = argv[++i];
        }
        else if (arg == "-java_home")
        {
            startArgs->javaHome = argv[++i];
        }
        else
        {
            startArgs->args.emplace_back(argv[i]);
        }
        i++;
    }
    return startArgs;
}
