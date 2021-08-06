#include <iostream>
#include "zip/unzip_entry.h"
using namespace std;

int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    //kubazip demo
    // auto buf = readZipEntry("./foo.zip", "foo-1.txt");
    // size_t length = strlenZipEntry(buf);
    // std::cout << length << std::endl;
    // for (int i = 0; i < length; i++) {
    //     std::cout << buf[i] - 0 << buf[i] << std::endl;
    // }
    // free(buf);
    return 0;
}
