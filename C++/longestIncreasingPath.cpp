/**
 * @File    : longestIncreasingPath.cpp
 * @Brief   : 矩阵中的最长递增路径
 * @Link    : https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * @Author  : Wei Li
 * @Date    : 2021-09-01
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, columns;

    int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        rows = matrix.size();
        columns = matrix[0].size();
        auto memo = std::vector<std::vector<int>>(rows, std::vector<int>(columns));
        int ans = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                ans = std::max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

    int dfs(std::vector<std::vector<int>> &matrix, int row, int column, std::vector<std::vector<int>> &memo)
    {
        if (memo[row][column] != 0)
        {
            return memo[row][column];
        }
        ++memo[row][column];
        for (int i = 0; i < 4; ++i)
        {
            int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column])
            {
                memo[row][column] = std::max(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
            }
        }
        return memo[row][column];
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};

    Solution solution;
    auto longest_increasing_path = solution.longestIncreasingPath(matrix);
    std::cout << "The solution of this problem is " << longest_increasing_path << std::endl;

    return 0;
}
