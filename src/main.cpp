#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "start/start_args.h"
#include "classpath/ClassFileReader.h"
#include "classfile/ClassFile.h"
#include "test/test.h"

using namespace std;

//初始化logger
void initLogger(bool debug)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%^--%L--%$] [thread %t] %v");

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/toy_jvm.log", true);
    file_sink->set_level(spdlog::level::debug);
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%^--%L--%$] [thread %t] %v");

    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    auto logger = std::make_shared<spdlog::logger>("Logger", sinks.begin(), sinks.end());
    if (debug)
    {
        logger->set_level(spdlog::level::debug);
    }
    else
    {
        logger->set_level(spdlog::level::off);
    }

    logger->info("Spdlog init success!!!");
    spdlog::register_logger(logger);
}

int main(int argc, char **argv)
{
    auto startArgs = parseArgs(argc, argv);
    if (!startArgs)
    {
        return 0;
    }
    initLogger(startArgs->debug);
    spdlog::get("Logger")->info("Start Run Toy JVM!");

    ClassFileReader::get_instance().init(startArgs->jre, startArgs->classpath);
    size_t dataSize = 0;
    auto data = ClassFileReader::get_instance().readClass("java.lang.Object", dataSize);
    int status = 0;
    ClassFile cf{data, dataSize, status};
    free(data);
    spdlog::critical("magicNumber,hex:{0:x}", cf.getMagicNumber());
    spdlog::info("minor_version:{0},major_version:{1},constant_pool_size:{2}", cf.getMinorVersion(), cf.getMajorVersion(), cf.getConstantPoolCount());

    return 0;
}
