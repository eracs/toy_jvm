#include "test.h"
#include "../classpath/ClassFileReader.h"
#include "../classfile/ClassFile.h"
#include "../classfile/constant_pool/CONSTANT_Methodref_info.h"
#include "spdlog/spdlog.h"

using namespace std;

void run_test()
{

    size_t dataSize = 0;
    auto data = ClassFileReader::get_instance().readClass("test.Main", dataSize);
    int status = 0;
    ClassFile cf{data, dataSize, status};
    free(data);
    spdlog::critical("magicNumber,hex:{0:x}", cf.getMagicNumber());
    spdlog::info("minor_version:{0},major_version:{1},constant_pool_size:{2}", cf.getMinorVersion(), cf.getMajorVersion(), cf.getConstantPoolCount());

    auto &v = cf.getConstantPool()->getItems();
    int i = 0;
    for (auto &item : v)
    {
        i++;
        spdlog::info("cp index {0}, cp tag {1}", i, item->getTag());
    }
    ConstantInfo *ptr = v[0].get();
    CONSTANT_Methodref_info *ptr2 = static_cast<CONSTANT_Methodref_info *>(ptr);
    spdlog::info("test tag {0} ,cIndex {1}, nIndex {2}", ptr2->getTag(), ptr2->getClassIndex(), ptr2->getNameAndTypeIndex());
}
