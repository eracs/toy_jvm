#include <iostream>
#include "test/test.h"

using namespace std;

int main(int argc, char **argv)
{
    test_parse_start_args(argc, argv);
    test_search_zip_entry();
    return 0;
}
