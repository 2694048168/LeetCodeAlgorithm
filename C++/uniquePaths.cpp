/**
 * @File    : uniquePaths.cpp
 * @Brief   : 不同路径
 * @Link    : https://leetcode-cn.com/problems/unique-paths/
 * @Author  : Wei Li
 * @Date    : 2021-08-31
*/

#include <iostream>
#include <vector>

// 动态规划
class Solution2
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> f(m, std::vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            f[i][0] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

// 组合数学
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y)
        {
            ans = ans * x / y;
        }
        return ans;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int m = 3;
    int n = 2;

    Solution solution;
    auto unique_path = solution.uniquePaths(m, n);
    std::cout << "The solution of this problem is " << unique_path << std::endl;

    return 0;
}
