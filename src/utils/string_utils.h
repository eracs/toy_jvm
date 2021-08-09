//
// Created by eracs on 2021/8/8.
//

#ifndef TOY_JVM_STRING_UTILS_H
#define TOY_JVM_STRING_UTILS_H
#include <iostream>
#include <vector>

namespace string_util
{

    bool startsWith(const std::string &source, const std::string &head);

    bool endsWith(const std::string &source, const std::string &tail);

    std::vector<std::string> split(const std::string &string, const std::string &sep);

    void replace_self(std::string &source,
                      const std::string &old_value,
                      const std::string &new_value);

    std::string replace_all(const std::string source, const std::string &old_value, const std::string &new_value);

    std::string get_param_separator();

    std::string get_dot_separator();

    std::string get_path_separator();

    bool is_os_windows();

}

#endif //TESTFS_STRING_UTILS_H
