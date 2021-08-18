#include <iostream>
#include "start/start_args.h"
#include "start/init.h"

#include "test/test.h"

using namespace std;

int main(int argc, char **argv)
{
    auto startArgs = parseArgs(argc, argv);
    if (!startArgs)
    {
        return 0;
    }
    init(startArgs);
}
