#include <iostream>
#include "zip/unzip_entry.h"
#include "start/start_args.h"
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
    auto args = parseArgs(argc, argv);
    cout << "JAVA_HOME:" << args->javaHome << endl;
    cout << "CLASS_PATH:" << args->classpath << endl;
    cout << "SHOW_VESION:" << args->versionFlag << endl;
    cout << "SHOW_HELP:" << args->helpFlag << endl;
    cout << "---next jvm:" << args->args.size() << " counts options---" << endl;
    for (auto const &item : args->args)
    {
        cout << item << endl;
    }

    return 0;
}
