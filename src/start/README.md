### 启动参数解析

- [使用Clara开源库解析启动参数](https://github.com/catchorg/Clara)
- ```parseArgs```方法传入的参数即为C++ main方法传入的，该方法解析启动参数，如果参数返回为空（即打印帮助信息、打印版本信息或者解析出错），则应直接结束运行，不再执行
```
StartArgs *parseArgs(int argc, char *argv[])
```
