/**
 * @File    : rotateImage.cpp
 * @Brief   : 旋转图像
 * @Link    : https://leetcode-cn.com/problems/rotate-image/
 * @Author  : Wei Li
 * @Date    : 2021-07-23
*/

#include <iostream>
#include <vector>

// in-place
class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int temp = 0, n = matrix.size() - 1;
        for (int i = 0; i <= n / 2; ++i)
        {
            for (int j = i; j < n - i; ++j)
            {
                temp = matrix[j][n - i];
                matrix[j][n - i] = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = temp;
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

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 6},
                                            {7, 8, 9}};

    Solution solution;
    std::cout << "The original matrix: " << std::endl;
    DisplayElement(matrix);
    solution.rotate(matrix);
    std::cout << "The rotated matrix: " << std::endl;
    DisplayElement(matrix);

    return 0;
}
