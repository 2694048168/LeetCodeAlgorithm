/**
 * @File    : isScramble.cpp
 * @Brief   : 扰乱字符串
 * @Link    : https://leetcode-cn.com/problems/scramble-string/
 * @Author  : Wei Li
 * @Date    : 2021-09-01
*/

#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <algorithm>

class Solution
{
private:
    // 记忆化搜索存储状态的数组
    // -1 表示 false，1 表示 true，0 表示未计算
    int memo[30][30][31];
    std::string s1, s2;

public:
    bool checkIfSimilar(int i1, int i2, int length)
    {
        std::unordered_map<int, int> freq;
        for (int i = i1; i < i1 + length; ++i)
        {
            ++freq[s1[i]];
        }
        for (int i = i2; i < i2 + length; ++i)
        {
            --freq[s2[i]];
        }
        if (std::any_of(freq.begin(), freq.end(), [](const auto &entry)
                        { return entry.second != 0; }))
        {
            return false;
        }
        return true;
    }

    // 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
    bool dfs(int i1, int i2, int length)
    {
        if (memo[i1][i2][length])
        {
            return memo[i1][i2][length] == 1;
        }

        // 判断两个子串是否相等
        if (s1.substr(i1, length) == s2.substr(i2, length))
        {
            memo[i1][i2][length] = 1;
            return true;
        }

        // 判断是否存在字符 c 在两个子串中出现的次数不同
        if (!checkIfSimilar(i1, i2, length))
        {
            memo[i1][i2][length] = -1;
            return false;
        }

        // 枚举分割位置
        for (int i = 1; i < length; ++i)
        {
            // 不交换的情况
            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i))
            {
                memo[i1][i2][length] = 1;
                return true;
            }
            // 交换的情况
            if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i))
            {
                memo[i1][i2][length] = 1;
                return true;
            }
        }

        memo[i1][i2][length] = -1;
        return false;
    }

    bool isScramble(std::string s1, std::string s2)
    {
        memset(memo, 0, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.size());
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::string str1 = "abcde";
    std::string str2 = "caebd";
    // std::string str1 = "great";
    // std::string str2 = "rgeat";

    Solution solution;
    auto check_is_scramble = solution.isScramble(str1, str2);
    std::cout << "The solution of this problem is " << std::boolalpha << check_is_scramble << std::endl;

    return 0;
}
