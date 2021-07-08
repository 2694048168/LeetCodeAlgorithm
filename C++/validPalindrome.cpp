/**
 * @File    : validPalindrome.cpp
 * @Brief   : 验证回文字符串 Ⅱ 双指针 + 贪心策略
 * @Link    : https://leetcode-cn.com/problems/valid-palindrome-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-08
*/

#include <iostream>
#include <string>

class Solution
{
public:
    bool checkPalindrome(const std::string& s, int low, int high)
    {
        for (int i = low, j = high; i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(std::string s)
    {
        int low = 0, high = s.size() - 1;
        while (low < high)
        {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2)
            {
                ++low;
                --high;
            }
            else
            {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::string str = "abcfdba";
    std::string str = "aba";
    // std::string str = "abca";

    auto solution = Solution();
    bool check = solution.validPalindrome(str);
    std::cout << "The solution of this problem is : " << std::boolalpha << check << std::endl;
    
    return 0;
}
