/**
 * @File    : isMatchSimple.cpp
 * @Brief   : 通配符匹配
 * @Link    : https://leetcode-cn.com/problems/wildcard-matching/
 * @Author  : Wei Li
 * @Date    : 2021-08-17
*/

#include <iostream>
#include <string>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        auto allStars = [](const std::string &str, int left, int right)
        {
            for (int i = left; i < right; ++i)
            {
                if (str[i] != '*')
                {
                    return false;
                }
            }
            return true;
        };
        auto charMatch = [](char u, char v)
        {
            return u == v || v == '?';
        };

        while (s.size() && p.size() && p.back() != '*')
        {
            if (charMatch(s.back(), p.back()))
            {
                s.pop_back();
                p.pop_back();
            }
            else
            {
                return false;
            }
        }
        if (p.empty())
        {
            return s.empty();
        }

        int sIndex = 0, pIndex = 0;
        int sRecord = -1, pRecord = -1;
        while (sIndex < s.size() && pIndex < p.size())
        {
            if (p[pIndex] == '*')
            {
                ++pIndex;
                sRecord = sIndex;
                pRecord = pIndex;
            }
            else if (charMatch(s[sIndex], p[pIndex]))
            {
                ++sIndex;
                ++pIndex;
            }
            else if (sRecord != -1 && sRecord + 1 < s.size())
            {
                ++sRecord;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else
            {
                return false;
            }
        }
        return allStars(p, pIndex, p.size());
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // std::string str = "adceb";
    // std::string pattern = "*a*b";
    std::string str = "acdcb";
    std::string pattern = "a*c?b";

    Solution solution;
    bool is_match_simple = solution.isMatch(str, pattern);
    std::cout << "The solution of this problem is " << std::boolalpha << is_match_simple << std::endl;

    return 0;
}
