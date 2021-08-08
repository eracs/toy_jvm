#include <string>
#include <vector>

namespace string_util
{
    bool startsWith(const std::string &source, const std::string &head)
    {
        return head.size() <= source.size() && source.compare(0, head.size(), head) == 0;
    }

    bool endsWith(const std::string &source, const std::string &tail)
    {
        return tail.size() <= source.size() && source.compare(source.size() - tail.size(), tail.size(), tail) == 0;
    }

    std::vector<std::string> split(const std::string &string, const std::string &sep)
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
}
