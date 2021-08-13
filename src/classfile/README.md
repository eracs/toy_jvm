### 解析class文件
-------
#### class文件格式
参见Java虚拟机规范（Java SE 8版）[第4章中第4.1节](https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.1)
> u1:1个字节(8bit)
> u2:2个字节(16bit)
> u4:4个字节(32bit)
> 存储顺序为大端

```
/*
ClassFile {
    u4             magic;
    u2             minor_version;
    u2             major_version;
    u2             constant_pool_count;
    cp_info        constant_pool[constant_pool_count-1];
    u2             access_flags;
    u2             this_class;
    u2             super_class;
    u2             interfaces_count;
    u2             interfaces[interfaces_count];
    u2             fields_count;
    field_info     fields[fields_count];
    u2             methods_count;
    method_info    methods[methods_count];
    u2             attributes_count;
    attribute_info attributes[attributes_count];
}
*/
```
#### magic（魔数）
----
- MagicNumber一般用于标记文件的格式，放置于文件的开头（这也是改后缀名不会影响绝大多数软件判断文件的实际类型的原因）
- Java的字节码文件（即class文件）的MagicNumber固定为0xCAFEBABE
#### minor_version（次版本号）
---- 

次版本号和主版本号组成class文件的版本，Java虚拟机的不同版本支持的class文件版本不一样，次版本基本不再使用（都是0）
#### major_version（主版本号）
-----
Java SE 8的主版本号为52,Java有前向兼容的好习惯，Java SE 8 支持从45~52的主版本号，本项目也如此。对不支持的版本号应该抛出```java.lang.unsupportedClassVersionError```