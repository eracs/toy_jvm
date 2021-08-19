//
// Created by eracs on 2021/8/8.
//

#ifndef TOY_JVM_STRING_UTILS_H
#define TOY_JVM_STRING_UTILS_H
#include <iostream>
#include <vector>
#include <string>

namespace string_util
{

    bool startsWith(const std::string &source, const std::string &head);

    bool endsWith(const std::string &source, const std::string &tail);

    std::vector<std::string> split(const std::string &source, const std::string &sep);

    void replace_self(std::string &source,
                      const std::string &old_value,
                      const std::string &new_value);

    std::string replace_all(const std::string source, const std::string &old_value, const std::string &new_value);

    //获取启动参数中的参数分隔符
    std::string get_param_separator();
    //获取"."这个字符串
    std::string get_dot_separator();
    //获取路径分隔符，此处固定为通用的"/"
    std::string get_path_separator();
    //获取class文件后缀，即".class"
    std::string get_class_file_ext();
    //获取jar文件后缀，即".jar"
    std::string get_jar_file_ext();
    //获取zip文件后缀，即".zip"
    std::string get_zip_file_ext();
    //当前系统是否为windows
    bool is_os_windows();

}

#endif //TESTFS_STRING_UTILS_H
