/**
 * @File    : maximalSquare.cpp
 * @Brief   : 最大正方形 动态规划
 * @Link    : https://leetcode-cn.com/problems/maximal-square/
 * @Author  : Wei Li
 * @Date    : 2021-07-14
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size(), max_side = 0;
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                max_side = std::max(max_side, dp[i][j]);
            }
        }

        return max_side * max_side;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<char>> matrix = {{'1', '0', '1', '0', '0'}, 
                                            {'1', '0', '1', '1', '1'}, 
                                            {'1', '1', '1', '1', '1'}, 
                                            {'1', '0', '0', '1', '0'}};
    Solution solution;
    auto max_area = solution.maximalSquare(matrix);
    std::cout << "The solution of this problem is : " << max_area << std::endl;
    return 0;
}
