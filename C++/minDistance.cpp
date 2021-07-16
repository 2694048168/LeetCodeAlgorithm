/**
 * @File    : minDistance.cpp
 * @Brief   : 编辑距离 动态规划
 * @Link    : https://leetcode-cn.com/problems/edit-distance/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    size_t minDistance(std::string word1, std::string word2)
    {
        size_t m = word1.length(), n = word2.length();
        std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));
        for (size_t i = 0; i <= m; ++i)
        {
            for (size_t j = 0; j <= n; ++j)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                else
                {
                    dp[i][j] = std::min(dp[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1),
                                        std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }
        return dp[m][n];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::string word1 = "horse";
    // std::string word2 = "ros";

    std::string word1 = "intention";
    std::string word2 = "execution";

    Solution solution;
    size_t min_distance = solution.minDistance(word1, word2);
    std::cout << "The solution of this problem is " << min_distance << std::endl;

    return 0;
}
