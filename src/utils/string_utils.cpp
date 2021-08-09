#include "string_utils.h"

#ifdef _WINDOWS
const bool OS_WIN = true;
#else
const bool OS_WIN = false;
#endif

const std::string PATH_SEPARATOR = "/";
const std::string DOT_SEPARATOR = ".";
const std::string WIN_PARAM_SEPARATOR = ";";
const std::string UNIX_PARAM_SEPARATOR = ":";

std::string string_util::get_param_separator()
{
    if (OS_WIN)
    {
        return WIN_PARAM_SEPARATOR;
    }
    return UNIX_PARAM_SEPARATOR;
}

std::string string_util::get_dot_separator()
{
    return DOT_SEPARATOR;
}

std::string string_util::get_path_separator()
{
    return PATH_SEPARATOR;
}

std::string string_util::replace_all(const std::string source,
                                     const std::string &old_value,
                                     const std::string &new_value)
{
    std::string dest(source);
    string_util::replace_self(dest, old_value, new_value);
    return dest;
}

void string_util::replace_self(std::string &source,
                               const std::string &old_value,
                               const std::string &new_value)
{
    std::string::size_type index = source.find(old_value);
    while (index != std::string::npos)
    {
        source.replace(index, old_value.size(), new_value);
        index = source.find(old_value);
    }
}

bool string_util::is_os_windows()
{
    return OS_WIN;
}

std::vector<std::string> string_util::split(const std::string &string,
                                            const std::string &sep)
{
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type index = string.find(sep, start);
    while (index != std::string::npos)
    {
        result.push_back(string.substr(start, index - start));
        start = index + sep.size();
        index = string.find(sep, start);
    }
    result.push_back(string.substr(start));
    return result;
}

bool string_util::endsWith(const std::string &source,
                           const std::string &tail)
{
    return tail.size() <= source.size() && source.compare(source.size() - tail.size(), tail.size(), tail) == 0;
}

bool string_util::startsWith(const std::string &source,
                             const std::string &head)
{
    return head.size() <= source.size() && source.compare(0, head.size(), head) == 0;
}