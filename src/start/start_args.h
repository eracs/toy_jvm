//
// Created by eracs on 2021/7/21.
//

#ifndef TOY_JVM_START_ARGS_H
#define TOY_JVM_START_ARGS_H
#include <string>

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
