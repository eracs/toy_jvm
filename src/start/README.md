### 启动参数解析

- [使用Clara开源库解析启动参数](https://github.com/catchorg/Clara)
- ```parseArgs```方法传入的参数即为C++ main方法传入的，该方法解析启动参数，如果参数返回为空（即提前打印帮助信息或版本信息），则结束运行
```
StartArgs *parseArgs(int argc, char *argv[])
```
