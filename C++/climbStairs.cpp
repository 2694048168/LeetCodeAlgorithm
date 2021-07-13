/**
 * @File    : climbStairs.cpp
 * @Brief   : 爬楼梯 动态规划 注意处理边界条件
 * @Link    : https://leetcode-cn.com/problems/climbing-stairs/
 * @Author  : Wei Li
 * @Date    : 2021-07-13
*/

#include <iostream>
#include <vector>

class Solution1
{
public:
    int climbStairs(int n)
    {
        // 边界条件
        if (n <= 2)
        {
            return n;
        }

        std::vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            // 状态转移方程
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// 对动态规划进行空间压缩
class Solution
{
public:
    int climbStairs(int n)
    {
        // 边界条件
        if (n <= 2)
        {
            return n;
        }

        // 对动态规划进行空间压缩
        // std::vector<int> dp(n + 1, 1);
        int pre2 = 1, pre1 = 2, current;
        for (int i = 2; i < n; ++i)
        {
            // 状态转移方程
            // dp[i] = dp[i - 1] + dp[i - 2];
            current = pre1 + pre2;
            pre2 = pre1;
            pre1 = current;
        }

        return current;
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    int n = 2;
    // int n = 3;

    Solution solution;
    int num_methods = solution.climbStairs(n);
    std::cout << "The solution of this problem is : " << num_methods << std::endl;

    return 0;
}
