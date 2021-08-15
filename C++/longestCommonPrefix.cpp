/**
 * @File    : longestCommonPrefix.cpp
 * @Brief   : 最长公共前缀
 * @Link    : https://leetcode-cn.com/problems/longest-common-prefix/
 * @Author  : Wei Li
 * @Date    : 2021-08-15
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (!strs.size())
        {
            return "";
        }

        std::string prefix = strs[0];
        int count = strs.size();
        for (int i = 1; i < count; ++i)
        {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size())
            {
                break;
            }
        }
        return prefix;
    }

    std::string longestCommonPrefix(const std::string &str1, const std::string &str2)
    {
        int length = std::min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index])
        {
            ++index;
        }
        return str1.substr(0, index);
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::string> strs{"flower", "flow", "flight"};

    Solution solution;
    auto longest_prefix = solution.longestCommonPrefix(strs);
    std::cout << "The solution of this problem is that " << longest_prefix << std::endl;

    return 0;
}
