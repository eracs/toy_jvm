### constant_pool（常量池）结构
--------
详细文档可见[虚拟机规范](https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.4)

#### constant_info的通用结构
```
cp_info {
    u1 tag;
    u1 info[];
}
```
#### 常量池标签—名称对照表
| Constant Type | Value| 
| :----- | :----- | 
| CONSTANT_Class | 7 | 
| CONSTANT_Fieldref | 9 | 
| CONSTANT_Methodref | 10 | 
| CONSTANT_InterfaceMethodref | 11 | 
| CONSTANT_String | 8| 
| CONSTANT_Integer | 3 | 
| CONSTANT_Float | 4 | 
| CONSTANT_Long | 5 | 
| CONSTANT_Double | 6 | 
| CONSTANT_NameAndType | 12 | 
| CONSTANT_Utf8 | 1 | 
| CONSTANT_MethodHandle | 15 | 
| CONSTANT_MethodType | 16 | 
| CONSTANT_InvokeDynamic| 18 | 
