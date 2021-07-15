/**
 * @File    : longestCommonSubsequence.cpp
 * @Brief   : 最长公共子序列 动态规划
 * @Link    : https://leetcode-cn.com/problems/longest-common-subsequence/
 * @Author  : Wei Li
 * @Date    : 2021-07-15
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        size_t m = text1.length(), n = text2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (size_t i = 1; i <= m; ++i)
        {
            for (size_t j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::string text1 = "abcde";
    std::string text2 = "ace";

    // std::string text1 = "abc";
    // std::string text2 = "abc";

    // std::string text1 = "abc";
    // std::string text2 = "def";

    Solution solution;
    auto max_legth = solution.longestCommonSubsequence(text1, text2);
    std::cout << "The solution of this problem is " << max_legth << std::endl;

    return 0;
}
