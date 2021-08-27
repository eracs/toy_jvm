#include "init.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "start_args.h"
#include "../classpath/ClassFileReader.h"

//初始化日志
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

void init(std::shared_ptr<StartArgs> startArgs)
{
    initLogger(startArgs->isDebugMode());
    ClassFileReader::get_instance().init(startArgs->getClasspath(), startArgs->getJrePath());
    spdlog::get("Logger")->info("Start Run Toy JVM!");
}
