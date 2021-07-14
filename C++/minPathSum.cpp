/**
 * @File    : minPathSum.cpp
 * @Brief   : 最小路径和 二维动态规划
 * @Link    : https://leetcode-cn.com/problems/minimum-path-sum/
 * @Author  : Wei Li
 * @Date    : 2021-07-14
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution2
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int num_rows = grid.size(), num_columns = grid[0].size();
        // 状态转移方程
        std::vector<std::vector<int>> dp(num_rows, std::vector<int>(num_columns, 0));
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_columns; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[num_rows - 1][num_columns - 1];
    }
};


// 空间压缩 ---- 状态相关的只有上面和左边的
class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int num_rows = grid.size(), num_columns = grid[0].size();
        // 状态转移方程
        std::vector<int> dp(num_columns, 0);
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_columns; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = grid[i][j];
                }
                else if (i == 0)
                {
                    dp[j] = dp[j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    dp[j] = dp[j] + grid[i][j];
                }
                else
                {
                    dp[j] = std::min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[num_columns - 1];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::vector<std::vector<int>> grid = { {1, 3, 1},
    //                                        {1, 5, 1},
    //                                        {4, 2, 1} };
    std::vector<std::vector<int>> grid = {{1, 2, 3},
                                          {4, 5, 6}};

    Solution solution;
    auto min_path_sum = solution.minPathSum(grid);
    std::cout << "The solution of this problem is : " << min_path_sum << std::endl;

    return 0;
}
