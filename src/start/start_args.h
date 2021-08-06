//
// Created by eracs on 2021/7/21.
//
#include <vector>
#include <string>

#ifndef TOY_JVM_START_ARGS_H
#define TOY_JVM_START_ARGS_H

class StartArgs
{
public:
    StartArgs() = default;
    bool helpFlag;
    bool versionFlag;
    std::string classpath;
    std::string javaHome;
    std::vector<std::string> args;
};

StartArgs *parseArgs(int argc, char *argv[]);

#endif //TOY_JVM_START_ARGS_H
