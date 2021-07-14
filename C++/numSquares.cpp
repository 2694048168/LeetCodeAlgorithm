/**
 * @File    : numSquares.cpp
 * @Brief   : 完全平方数 动态规划
 * @Link    : https://leetcode-cn.com/problems/perfect-squares/
 * @Author  : Wei Li
 * @Date    : 2021-07-14
*/

#include <iostream>
#include <vector>
#include <cmath>

class Solution2
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// 数学
class Solution
{
public:
    // 判断是否为完全平方数
    bool isPerfectSquare(int x)
    {
        int y = std::sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x)
    {
        while (x % 4 == 0)
        {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n)
    {
        if (isPerfectSquare(n))
        {
            return 1;
        }
        if (checkAnswer4(n))
        {
            return 4;
        }
        for (int i = 1; i * i <= n; i++)
        {
            int j = n - i * i;
            if (isPerfectSquare(j))
            {
                return 2;
            }
        }
        return 3;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // int n = 12;
    int n = 13;

    Solution solution;
    auto num_sequares = solution.numSquares(n);
    std::cout << "The solution of this problem is " << num_sequares << std::endl;

    return 0;
}
