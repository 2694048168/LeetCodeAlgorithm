/**
 * @File    : updateMatrix.cpp
 * @Brief   : 01 矩阵 动态规划  
 * @Link    : https://leetcode-cn.com/problems/01-matrix/
 * @Author  : Wei Li
 * @Date    : 2021-07-14
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        int rows = matrix.size(), columns = matrix[0].size();
        std::vector<std::vector<int>> dp(rows, std::vector<int>(columns, INT_MAX - 1));
        // 从 左上 到 右下 的动态搜索
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (j > 0)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
                    }
                    if (i > 0)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
                    }
                }
            }
        }

        // 从 右下 到 左上 的动态搜索
        for (int i = rows - 1; i >= 0; --i)
        {
            for (int j = columns - 1; j >= 0; --j)
            {
                if (matrix[i][j] != 0)
                {
                    if (j < columns - 1)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i][j + 1] + 1);
                    }
                    if (i < rows - 1)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + 1);
                    }
                }
            }
        }

        return dp;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        for (auto value = element->begin(); value != element->end(); ++value)
        {
            std::cout << *value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matrix = { {0, 0, 0},
                                             {0, 1, 0},
                                             {1, 1, 1} };
    // std::vector<std::vector<int>> matrix = { {0, 0, 0},
    //                                          {0, 1, 0},
    //                                          {0, 0, 0} };

    Solution solution;
    auto update_mat = solution.updateMatrix(matrix);
    std::cout << "Before Update the Matrix: " << std::endl;
    DisplayElement(matrix);

    std::cout << "After Update the Matrix: " << std::endl;
    DisplayElement(update_mat);

    return 0;
}
