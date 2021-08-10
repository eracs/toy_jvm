#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

#include "test/test.h"

using namespace std;

void initLogger()
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::info);
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%n] [%^--%L--%$] [thread %t] %v");

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/toy_jvm.log", true);
    file_sink->set_level(spdlog::level::trace);
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%n] [%^--%L--%$] [thread %t] %v");

    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    auto logger = std::make_shared<spdlog::logger>("Logger", sinks.begin(), sinks.end());
    logger->set_level(spdlog::level::debug);
    logger->info("Spdlog init success!!!");
    spdlog::register_logger(logger);
}

int main(int argc, char **argv)
{
    initLogger();
    spdlog::get("Logger")->info("Start Run Toy JVM!");
    run_test(argc, argv);
    return 0;
}
