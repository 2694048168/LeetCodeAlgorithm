/**
 * @File: sub_sequence.cpp
 * @Brief: 判断子序列
 * @Link: https://leetcode.cn/problems/is-subsequence/
 * @Author: Wei Li (weili_yzzcq@163.com)
 * @Date: 2022-09-24
*/

#include <iostream>
#include <string>
#include <map>


class Solution 
{
public:
    bool isSubsequence(std::string s, std::string t) 
    {
        int first_ptr_s = 0, second_ptr_t = 0; /* 双指针思想 */
        while (first_ptr_s < s.length() && second_ptr_t < t.length())
        {
            if (s[first_ptr_s] == t[second_ptr_t]) /* 贪心思想 */
            {
                ++first_ptr_s;
            }
            ++second_ptr_t;
        }

        return first_ptr_s == s.length(); /* s 是否匹配结束 */
    }
};


// -----------------------------
int main(int argc, char **argv)
{
    std::string str_1 = "axc";
    std::string str_2 = "ahbgdc";
    // std::string str_1 = "abc";
    // std::string str_2 = "ahbgdc";

    Solution solution;
    auto sub_sequence = solution.isSubsequence(str_1, str_2);
    std::cout << "The solution of this problem is " << std::boolalpha << sub_sequence << std::endl;

    return 0;
}
