/**
 * @File    : longestPalindrome.cpp
 * @Brief   : 最长回文串 区分大小写
 * @Link    : https://leetcode-cn.com/problems/longest-palindrome/
 * @Author  : Wei Li
 * @Date    : 2021-07-29
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int longestPalindrome(std::string s)
    {
        std::unordered_map<char, int> count;
        int ans = 0;
        for (char c : s)
            ++count[c];
        for (auto p : count)
        {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 and ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // std::string str = "abccccdd";
    std::string str = "AbcCccdD";

    Solution solution;
    auto longest_palindrome = solution.longestPalindrome(str);
    std::cout << "The solution of this problem is " << longest_palindrome << std::endl;

    return 0;
}
