### 搜索并读取class文件
-----
- 实现方式参考[《自己动手写Java虚拟机》](https://book.douban.com/subject/26802084/)第2章，但ClassEntry仅有Dir和Zip两个子类，分别封装从Zip中读取和路径中直接读取两种方式。
- 解析jre路径、jre/lib路径时会将路径下的所有jar包/zip包添加进来，解析classpath路径时会将每个classpath路径下的所有jar包/zip包添加进来，同时路径本身也会作为dir_entry添加
- ClassFileReader作为实现为单例模式，提供统一接口```uint8 *readClass(const std::string &className, size_t &length);```
- 读入进来的数据为unsigned char*,即byte[]数组，使用kubazip/zip项目demo中的别名uint8,因为本人暂时不确定uint8_t,uint16_t是否在每个平台都有