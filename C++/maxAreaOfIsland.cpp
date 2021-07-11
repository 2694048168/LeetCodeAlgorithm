/**
 * @File    : maxAreaOfIsland.cpp
 * @Brief   : 岛屿的最大面积,二维矩阵的搜索
 * @Link    : https://leetcode-cn.com/problems/max-area-of-island/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <memory>

// 使用 栈 完成深度优先搜索
class Solution1
{
    std::vector<int> direction{-1, 0, 1, 0, -1};

public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    local_area = 1;
                    grid[i][j] = 0;
                    std::stack<std::pair<int, int>> island;
                    island.push({i, j});
                    while (!island.empty())
                    {
                        // auto [r, c] = island.top(); // C++17
                        auto r = island.top().first;
                        auto c = island.top().second;
                        island.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            x = r + direction[k], y = c + direction[k + 1];
                            if (x >= 0 && x < m &&
                                y >= 0 && y < n && grid[x][y] == 1)
                            {
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }
                    }
                    area = std::max(area, local_area);
                }
            }
        }
        return area;
    }
};

// 使用 递归 完成深度优先搜索
class Solution2
{
    std::vector<int> direction{-1, 0, 1, 0, -1};

public:
    // 主函数
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    max_area = std::max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    // 辅函数
    // 在辅函数里，一个一定要注意的点是辅函数内递归搜索时，边界条件的判定
    int dfs(std::vector<std::vector<int>> &grid, int r, int c)
    {
        if (grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i)
        {
            x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
            {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};

// 使用 递归 完成深度优先搜索
class Solution
{
    std::vector<int> direction{-1, 0, 1, 0, -1};

public:
    // 主函数
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                max_area = std::max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }
    // 辅函数
    // 在辅函数里，一个一定要注意的点是辅函数内递归搜索时，边界条件的判定
    int dfs(std::vector<std::vector<int>> &grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() || grid[r][c] == 0)
        {
            return 0;
        }
        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) +
               dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }
};


// ----------------------------------
int main(int argc, char **argv)
{
    // std::vector<std::vector<int>> grid = {{0,0,0,0,0,0,0,0}};
    std::vector<std::vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                          {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    // Solution solution;
    // auto max_area = solution.maxAreaOfIsland(grid);
    // std::cout << "The solution of this problem is : " << max_area << std::endl;

    auto solution = std::make_unique<Solution>();
    auto max_area = solution->maxAreaOfIsland(grid);
    // auto max_area = (*solution).maxAreaOfIsland(grid);
    std::cout << "The solution of this problem is : " << max_area << std::endl;

    return 0;
}
