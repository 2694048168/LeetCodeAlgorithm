/**
 * @File    : isPalindromeCheck.cpp
 * @Brief   : 验证回文串
 * @Link    : https://leetcode-cn.com/problems/valid-palindrome/
 * @Author  : Wei Li
 * @Date    : 2021-08-26
*/

#include <iostream>
#include <string>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                ++left;
            }
            while (left < right && !isalnum(s[right]))
            {
                --right;
            }
            if (left < right)
            {
                if (tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::string str = "A man, a plan, a canal: Panama";
    // std::string str = "race a car";
    // std::string str = "";
    std::string str = " ";

    Solution solution;
    bool check_palindrome = solution.isPalindrome(str);
    std::cout << "The solution of this problem is " << std::boolalpha << check_palindrome << std::endl;

    return 0;
}
