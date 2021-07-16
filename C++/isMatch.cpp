/**
 * @File    : isMatch.cpp
 * @Brief   : 正则表达式匹配 动态规划
 * @Link    : https://leetcode-cn.com/problems/regular-expression-matching/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        int m = s.size(), n = p.size();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < n + 1; ++i)
        {
            if (p[i - 1] == '*')
            {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] != '*')
                {
                    dp[i][j] = dp[i - 1][j - 1] && p[j - 1] == s[i - 1];
                }
                else if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                {
                    dp[i][j] = dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
                }
            }
        }
        return dp[m][n];
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::string s = "aa", p = "a";
    // std::string s = "aa", p = "a*";
    std::string s = "ab", p = "a.";

    Solution solution;
    bool check_match = solution.isMatch(s, p);
    std::cout << "The solution of this problem is " << std::boolalpha << check_match << std::endl;

    return 0;
}
