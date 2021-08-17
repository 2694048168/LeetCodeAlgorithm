/**
 * @File    : longestValidParentheses.cpp
 * @Brief   : 最长有效括号
 * @Link    : https://leetcode-cn.com/problems/longest-valid-parentheses/
 * @Author  : Wei Li
 * @Date    : 2021-08-17
*/

#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
            {
                maxlength = std::max(maxlength, 2 * right);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
            {
                maxlength = std::max(maxlength, 2 * left);
            }
            else if (left > right)
            {
                left = right = 0;
            }
        }
        return maxlength;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::string str = "(()";
    std::string str = ")()())";

    Solution solution;
    int longest_valid_parenttheses = solution.longestValidParentheses(str);
    std::cout << "The solution of this problem is " << longest_valid_parenttheses << std::endl;

    return 0;
}
