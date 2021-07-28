/**
 * @File    : countBinarySubstrings.cpp
 * @Brief   : 计数二进制子串
 * @Link    : https://leetcode-cn.com/problems/count-binary-substrings/
 * @Author  : Wei Li
 * @Date    : 2021-07-28
*/

#include <iostream>
#include <string>

class Solution
{
public:
    int countBinarySubstrings(std::string s)
    {
        int pre = 0, cur = 1, count = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                ++cur;
            }
            else
            {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur)
            {
                ++count;
            }
        }
        return count;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::string str = "00110011";
    std::string str = "10101";

    Solution solution;
    auto num_binary_substring = solution.countBinarySubstrings(str);
    std::cout << "The solution of this problem is " << num_binary_substring << std::endl;

    return 0;
}
