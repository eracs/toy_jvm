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


#### 踩坑分析
- 索引从1开始，这个一般不会踩坑
- Long和Double会占用两个索引，即Long/Double的索引为n的话，下一个可用位置为n+2,n+1被视为有效但不使用的索引
> In retrospect, making 8-byte constants take two constant pool entries was a poor choice.


#### 数据转换思路
- utf-8这个直接放进std::string里，暂时没思路
- Java的Integer转int，在二进制表现上是一样的，直接转
- Java的Long转long long，也是一样
- C++的浮点数规范和Java的浮点数规范都是遵循IEEE 754标准，所以在二进制表现上也是一样的，但是虚拟机规范上规定了NaN,正负无穷三种值，需要特殊处理
