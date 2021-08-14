/**
 * @File    : maximalRectangle.cpp
 * @Brief   : 最大矩形
 * @Link    : https://leetcode-cn.com/problems/maximal-rectangle/
 * @Author  : Wei Li
 * @Date    : 2021-08-14
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        std::vector<std::vector<int>> left(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++)
        { // 对于每一列，使用基于柱状图的方法
            std::vector<int> up(m, 0), down(m, 0);

            std::stack<int> stk;
            for (int i = 0; i < m; i++)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = std::stack<int>();
            for (int i = m - 1; i >= 0; i--)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++)
            {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = std::max(ret, area);
            }
        }
        return ret;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<char>> matrix{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    Solution solution;
    auto max_area_matrix = solution.maximalRectangle(matrix);
    std::cout << "The solution of this problem is " << max_area_matrix << std::endl;

    return 0;
}
