/**
 * @File    : findNumberIn2DArray.cpp
 * @Brief   : 二维数组中的查找
 * @Link    : https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-06
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target)
    {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] > target)
                --i;
            else if (matrix[i][j] < target)
                ++j;
            else
                return true;
        }
        return false;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matrix{{1, 4, 7, 11, 15},
                                         {2, 5, 8, 12, 19},
                                         {3, 6, 9, 16, 22},
                                         {10, 13, 14, 17, 24},
                                         {18, 21, 23, 26, 30}};
    int target = 5;
    // int target = 20;

    Solution solution;
    bool find_number_array = solution.findNumberIn2DArray(matrix, target);
    std::cout << "The solution of this problem is " << std::boolalpha << find_number_array << std::endl;

    return 0;
}
