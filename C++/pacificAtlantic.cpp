/**
 * @File    : pacificAtlantic.cpp
 * @Brief   : 太平洋大西洋水流问题
 * @Link    : https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <vector>

class Solution
{
    std::vector<int> direction{-1, 0, 1, 0, -1};

public:
    // 主函数
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return {};
        }
        std::vector<std::vector<int>> ans;
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<bool>> can_reach_p(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> can_reach_a(m, std::vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            dfs(matrix, can_reach_p, i, 0);
            dfs(matrix, can_reach_a, i, n - 1);
        }
        for (int i = 0; i < n; ++i)
        {
            dfs(matrix, can_reach_p, 0, i);
            dfs(matrix, can_reach_a, m - 1, i);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; ++j)
            {
                if (can_reach_p[i][j] && can_reach_a[i][j])
                {
                    ans.push_back(std::vector<int>{i, j});
                }
            }
        }
        return ans;
    }

    // 辅函数
    void dfs(const std::vector<std::vector<int>> &matrix, std::vector<std::vector<bool>> &can_reach,
             int r, int c)
    {
        if (can_reach[r][c])
        {
            return;
        }
        can_reach[r][c] = true;
        int x, y;
        for (int i = 0; i < 4; ++i)
        {
            x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
                matrix[r][c] <= matrix[x][y])
            {
                dfs(matrix, can_reach, x, y);
            }
        }
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
