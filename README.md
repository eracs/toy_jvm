# Toy_Jvm
----------
![GitHub](https://img.shields.io/github/license/eracs/toy_jvm)![GitHub top language](https://img.shields.io/github/languages/top/eracs/toy_jvm)![GitHub last commit](https://img.shields.io/github/last-commit/eracs/toy_jvm)![GitHub contributors](https://img.shields.io/github/contributors/eracs/toy_jvm)![GitHub issues](https://img.shields.io/github/issues-raw/eracs/toy_jvm)
-----------
使用C++实现的JVM，使用Xmake构建，支持跨平台。JVM特性基于Java SE 8规范。             

## 构建步骤

----------

 1.  搭建C++编译环境
 2.  [安装vcpkg](https://github.com/microsoft/vcpkg)
 3.  [安装xmake](https://xmake.io/#/zh-cn/guide/installation)![Xmake](https://img.shields.io/badge/xmake-%3E%3Dv2.5.6-orange)
 4.  clone代码到本地 
   ```  git clone https://github.com/eracs/toy_jvm.git ```
 4.  使用xmake构建
   ```  xmake build   ```

## 功能实现

----------

- [x] [搜索Class文件](https://github.com/eracs/toy_jvm/tree/master/src/classpath)
- [ ] [解析Class文件](https://github.com/eracs/toy_jvm/tree/master/src/classfile)
- [ ] 校验字节码 
- [ ] 执行字节码
- [ ] 加载类
- [ ] 调用方法
- [ ] 实例化
- [ ] 本地方法
- [ ] 异常处理
- [ ] GC
- [ ] 多线程
## 参考资料
--------
#### 实现思路
- [《自己动手写Java虚拟机》](https://book.douban.com/subject/26802084/)
#### 虚拟机规范：
- [《The Java® Virtual Machine Specification - Java SE 8 Edition》](https://docs.oracle.com/javase/specs/jvms/se8/html/) 
- 中文版 [《Java虚拟机规范（Java SE 8版）》](https://book.douban.com/subject/26418340/) 
#### 其他参考书目
- [《深入理解Java虚拟机（第三版）》](https://book.douban.com/subject/34907497/)
- [《垃圾回收的算法与实现》](https://book.douban.com/subject/26821357/)



