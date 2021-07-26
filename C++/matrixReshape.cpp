/**
 * @File    : matrixReshape.cpp
 * @Brief   : 重塑矩阵
 * @Link    : https://leetcode-cn.com/problems/reshape-the-matrix/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &nums, int r, int c)
    {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c)
        {
            return nums;
        }

        std::vector<std::vector<int>> ans(r, std::vector<int>(c));
        for (int x = 0; x < m * n; ++x)
        {
            ans[x / c][x % c] = nums[x / n][x % n];
        }
        return ans;
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
    std::vector<std::vector<int>> nums{{1, 2}, {3, 4}};
    // int r = 1, c = 4;
    int r = 2, c = 4;

    Solution solution;
    auto reshape_matrix = solution.matrixReshape(nums, r, c);
    std::cout << "The original matrix is that: " << std::endl;
    DisplayElement(nums);
    std::cout << "The reshape matrix is that: " << std::endl;
    DisplayElement(reshape_matrix);

    return 0;
}
