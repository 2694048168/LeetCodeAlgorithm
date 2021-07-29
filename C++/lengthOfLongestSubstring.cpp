/**
 * @File    : lengthOfLongestSubstring.cpp
 * @Brief   : 无重复字符的最长子串
 * @Link    : https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * @Author  : Wei Li
 * @Date    : 2021-07-29
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        // 哈希集合，记录每个字符是否出现过
        std::unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1]))
            {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = std::max(ans, rk - i + 1);
        }
        return ans;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    std::string str = "abcabcbb";

    Solution solution;
    auto length_longest_substring = solution.lengthOfLongestSubstring(str);
    std::cout << "The solution of this problem is " << length_longest_substring << std::endl;

    return 0;
}
