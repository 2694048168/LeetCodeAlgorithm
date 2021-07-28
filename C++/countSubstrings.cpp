/**
 * @File    : countSubstrings.cpp
 * @Brief   : 回文子串
 * @Link    : https://leetcode-cn.com/problems/palindromic-substrings/
 * @Author  : Wei Li
 * @Date    : 2021-07-28
*/

#include <iostream>
#include <string>

class Solution
{
public:
    int countSubstrings(std::string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            count += extendSubstrings(s, i, i);     // 奇数长度
            count += extendSubstrings(s, i, i + 1); // 偶数长度
        }
        return count;
    }
    int extendSubstrings(std::string s, int l, int r)
    {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // std::string str = "aaa";
    std::string str = "abc";

    Solution solution;
    auto num_substring = solution.countSubstrings(str);
    std::cout << "The solution of this problem is " << num_substring << std::endl;

    return 0;
}
