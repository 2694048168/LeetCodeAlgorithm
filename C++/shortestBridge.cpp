/**
 * @File    : shortestBridge.cpp
 * @Brief   :  最短的桥 广度优先搜索
 * @Link    : https://leetcode-cn.com/problems/shortest-bridge/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Solution
{
    std::vector<int> direction{-1, 0, 1, 0, -1};

public:
    // 主函数
    int shortestBridge(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        std::queue<std::pair<int, int>> points;
        // dfs寻找第一个岛屿， 并把1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; ++i)
        {
            if (flipped)
                break;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿， 并把过程中经过的0赋值为2
        int x, y;
        int level = 0;
        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                // auto [r, c] = points.front(); // c++17
                auto r = points.front().first;
                auto c = points.front().second;
                points.pop();
                for (int k = 0; k < 4; ++k)
                {
                    x = r + direction[k], y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }
                        if (grid[x][y] == 1)
                        {
                            return level;
                        }
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }
    // 辅函数
    void dfs(std::queue<std::pair<int, int>> &points, std::vector<std::vector<int>> &grid, int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    // std::vector<std::vector<int>> grid{{0, 1}, {1, 0}};
    // std::vector<std::vector<int>> grid{{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> grid{{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};

    Solution solution;
    auto min_bridge = solution.shortestBridge(grid);
    std::cout << "The solutio of this problem i s: " << min_bridge << std::endl;

    return 0;
}
