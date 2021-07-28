/**
 * @File    : strStr.cpp
 * @Brief   : 实现 strStr()
 * @Link    : https://leetcode-cn.com/problems/implement-strstr/
 * @Author  : Wei Li
 * @Date    : 2021-07-28
*/

#include <iostream>
#include <string>
#include <vector>

// Knuth-Morris-Pratt（KMP）算法，可以在 big-O(m + n) 时间利用动态规划完成匹配
class Solution
{
public:
    // 主函数
    int strStr(std::string haystack, std::string needle)
    {
        int k = -1, n = haystack.length(), p = needle.length();
        if (p == 0)
            return 0;
        std::vector<int> next(p, -1); // -1表示不存在相同的最大前缀和后缀
        calNext(needle, next);   // 计算next数组
        for (int i = 0; i < n; ++i)
        {
            while (k > -1 && needle[k + 1] != haystack[i])
            {
                k = next[k]; // 有部分匹配， 往前回溯
            }
            if (needle[k + 1] == haystack[i])
            {
                ++k;
            }
            if (k == p - 1)
            {
                return i - p + 1; // 说明k移动到needle的最末端， 返回相应的位置
            }
        }
        return -1;
    }
    // 辅函数 - 计算next数组
    void calNext(const std::string &needle, std::vector<int> &next)
    {
        for (int j = 1, p = -1; j < needle.length(); ++j)
        {
            while (p > -1 && needle[p + 1] != needle[j])
            {
                p = next[p]; // 如果下一位不同， 往前回溯
            }
            if (needle[p + 1] == needle[j])
            {
                ++p; // 如果下一位相同， 更新相同的最大前缀和最大后缀长
            }
            next[j] = p;
        }
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    std::string str1 = "hello", str2 = "ll";

    Solution solution;
    auto str2str = solution.strStr(str1, str2);
    std::cout << "The solution of this problem is " << str2str << std::endl;

    return 0;
}
