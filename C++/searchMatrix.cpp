/**
 * @File    : searchMatrix.cpp
 * @Brief   : 搜索二维矩阵 II
 * @Link    : https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-23
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        return false;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15},
                                            {2, 5, 8, 12, 19},
                                            {3, 6, 9, 16, 22},
                                            {10, 13, 14, 17, 24},
                                            {18, 21, 23, 26, 30}};
    // int target = 5;
    int target = 50;

    Solution solution;
    bool check_matrix = solution.searchMatrix(matrix, target);
    std::cout << "The solution of this problem is " << std::boolalpha << check_matrix << std::endl;

    return 0;
}
