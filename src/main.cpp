#include <iostream>
#include "start/start_args.h"
#include "start/init.h"

#include "test/test.h"

using namespace std;

int main(int argc, char **argv)
{
    //解析启动参数
    auto startArgs = parseArgs(argc, argv);
    if (!startArgs)
    {
        //打印帮助或版本信息/启动参数不完整
        return 0;
    }
    //初始化
    init(startArgs);
    run_test();
}
