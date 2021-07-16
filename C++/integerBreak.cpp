/**
 * @File    : integerBreak.cpp
 * @Brief   : 整数拆分 动态规划
 * @Link    : https://leetcode-cn.com/problems/integer-break/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n < 4)
        {
            return n - 1;
        }
        std::vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = std::max(std::max(2 * (i - 2), 2 * dp[i - 2]), std::max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int n = 2;

    Solution solution;
    auto max_mul = solution.integerBreak(n);
    std::cout << "The solution of this problem is " << max_mul << std::endl;

    return 0;
}
