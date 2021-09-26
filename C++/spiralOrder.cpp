/**
 * @File    : spiralOrder.cpp
 * @Brief   : 顺时针打印矩阵
 * @Link    : https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-26
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        std::vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom)
        {
            for (int column = left; column <= right; ++column)
            {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; ++row)
            {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom)
            {
                for (int column = right - 1; column > left; --column)
                {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; --row)
                {
                    order.push_back(matrix[row][left]);
                }
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return order;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution solution;
    auto spiral_order = solution.spiralOrder(matrix);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(spiral_order);

    return 0;
}
