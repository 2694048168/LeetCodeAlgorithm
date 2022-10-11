/**
 * @file almost_equal.cpp
 * @author Wei Li (weili_yzzcq@163.com)
 * @brief 仅执行一次字符串交换能否使两个字符串相等
 * @cite https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 长度相等的两个字符串 s1 和 s2, 一次字符串交换操作的步骤如下：
 * 选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。
 * 如果对 其中一个字符串 执行 最多一次字符串交换 就可以使两个字符串相等，返回 true ；否则，返回 false 。
 *
 * solution:
 * 题目要求其中一个字符串执行最多一次字符交换使得两个字符串相等，
 * 意味着两个字符串中最多只存在两个位置 i,j 处字符不相等，此时交换 i,j 处字符可使其相等。
 * 设两个字符串分别为 s_1,s_2：
 * 1. 如果两个字符串 s_1,s_2s 相等，则不需要进行交换即可满足相等；
 * 2. 如果两个字符串 s_1,s_2s 不相等，字符串一定存在两个位置 i,j 处的字符不相等，
 *     需要交换 i,j 处字符使其相等，此时一定满足 s_1[i] = s_2[j], s_1[j] = s_2[i];
 * 如果两个字符中只存在一个或大于两个位置的字符不相等，则此时无法通过一次交换使其相等；
 *
 */
class Solution
{
public:
    bool areAlmostEqual(std::string str1, std::string str2)
    {
        // special case
        if (str1.empty() || (str1.size() != str2.size()))
        {
            return false;
        }

        std::vector<int> diff_char;
        // case 1. 遍历所有索引，只要对应索引字符不相等，则将索引存入vector
        // 如果不相等的字符总数超过 2， 则不满足要求，直接 false
        for (int i = 0; i < str1.length(); ++i)
        {
            if (str1[i] != str2[i])
            {
                diff_char.emplace_back(i);
                if (diff_char.size() > 2)
                {
                    return false;
                }
            }
        }
        if (diff_char.size() == 0) /* case2. 如果两个字符串完全相等，直接 true */
        {
            return true;
        }
        else if (diff_char.size() == 1) /* case 3. 如果两个字符串唯有一个字符不同，直接 false */
        {
            return false;
        }
        else /* case 4. 如果两个字符串只有两个字符不同，则判断是否可以交换相同，可以则为true，否则false */
        {
            return (str1[diff_char[0]] == str2[diff_char[1]]) && (str1[diff_char[1]] == str2[diff_char[0]]);
        }
    }
};

// ------------------------------------
int main(int argc, char const *argv[])
{
    // std::string s1 = "bank", s2 = "kanb"; /* True */
    std::string s1 = "yhy", s2 = "hyc"; /* False */
    // std::string s1 = "abcd", s2 = "dcba"; /* False */
    // std::string s1 = "attack", s2 = "defend"; /* False */
    // std::string s1 = "bank", s2 = "bank"; /* True */

    Solution solution;
    bool equal_str = solution.areAlmostEqual(s1, s2);
    std::cout << "this two string is equal: " << std::boolalpha << equal_str << std::endl;

    return 0;
}
