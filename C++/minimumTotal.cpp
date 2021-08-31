/**
 * @File    : minimumTotal.cpp
 * @Brief   : 三角形最小路径和
 * @Link    : https://leetcode-cn.com/problems/triangle/
 * @Author  : Wei Li
 * @Date    : 2021-08-31
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        int n = triangle.size();
        std::vector<std::vector<int>> f(2, std::vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            int curr = i % 2;
            int prev = 1 - curr;
            f[curr][0] = f[prev][0] + triangle[i][0];
            for (int j = 1; j < i; ++j)
            {
                f[curr][j] = std::min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
            }
            f[curr][i] = f[prev][i - 1] + triangle[i][i];
        }
        return *min_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    Solution solution;
    auto mini_num_total = solution.minimumTotal(triangle);
    std::cout << "The solution of this problem is " << mini_num_total << std::endl;

    return 0;
}
