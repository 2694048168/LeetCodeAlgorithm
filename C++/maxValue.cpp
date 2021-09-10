/**
 * @File    : maxValue.cpp
 * @Brief   : 礼物的最大价值
 * @Link    : https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-10
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxValue(std::vector<std::vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
        {
            return 0;
        }
        int m = grid[0].size();
        std::vector<int> dp(m, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < m; j++)
        {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            dp[0] = dp[0] + grid[i][0];
            int tmp = 0;
            for (int j = 1; j < m; j++)
            {
                tmp = dp[j];
                dp[j] = std::max(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[m - 1];
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution solution;
    auto max_value = solution.maxValue(grid);
    std::cout << "The solution of this problem is " << max_value << std::endl;

    return 0;
}
