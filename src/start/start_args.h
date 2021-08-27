#ifndef TOY_JVM_START_ARGS_H
#define TOY_JVM_START_ARGS_H

#include <string>
#include <memory>

class StartArgs
{
private:
    std::string classpath;
    std::string jre;
    bool debug;

public:
    StartArgs(std::string classpath, std::string jre, bool debug);

    const std::string &getClasspath() const;

    const std::string &getJrePath() const;

    const bool isDebugMode() const;
};

//parse start args(such as jre, classpath, etc.)
std::shared_ptr<StartArgs> parseArgs(int argc, char *argv[]);

#endif //TOY_JVM_START_ARGS_H
