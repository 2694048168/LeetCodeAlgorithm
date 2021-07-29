/**
 * @File    : longestSubPalindrome.cpp
 * @Brief   : 最长回文子串
 * @Link    : https://leetcode-cn.com/problems/longest-palindromic-substring/
 * @Author  : Wei Li
 * @Date    : 2021-07-29
*/

#include <iostream>
#include <string>
#include <utility>


// 方法一：动态规划
// 方法三：Manacher 算法
// 方法二：中心扩展算法
class Solution
{
public:
    std::pair<int, int> expandAroundCenter(const std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    std::string longestPalindrome(std::string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);     // C++17
            auto [left2, right2] = expandAroundCenter(s, i, i + 1); // c++17
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::string str = "cbbd";

    Solution solution;
    auto longest_palindrom = solution.longestPalindrome(str);
    std::cout << "The solution of this problem is " << longest_palindrom << std::endl;

    return 0;
}
