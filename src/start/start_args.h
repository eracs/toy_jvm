//
// Created by eracs on 2021/7/21.
//
#include <string>

#ifndef TOY_JVM_START_ARGS_H
#define TOY_JVM_START_ARGS_H

class StartArgs
{
public:
    StartArgs() = default;
    std::string classpath;
    std::string jre;
    std::string command;
};

StartArgs *parseArgs(int argc, char *argv[]);

#endif //TOY_JVM_START_ARGS_H
