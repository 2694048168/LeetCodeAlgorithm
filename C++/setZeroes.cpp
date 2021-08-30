/**
 * @File    : setZeroes.cpp
 * @Brief   : 矩阵置零
 * @Link    : https://leetcode-cn.com/problems/set-matrix-zeroes/
 * @Author  : Wei Li
 * @Date    : 2021-08-30
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        for (int i = 0; i < m; i++)
        {
            if (!matrix[i][0])
            {
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
            if (flag_col0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        for (auto value : element)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// ----------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matrx = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    Solution solution;
    std::cout << "Processing before : " << std::endl; 
    DisplayElement(matrx);
    solution.setZeroes(matrx);
    std::cout << "Processing after : " << std::endl; 
    DisplayElement(matrx);

    return 0;
}
