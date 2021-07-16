/**
 * @File    : minSteps.cpp
 * @Brief   : 只有两个键的键盘 动态规划
 * @Link    : https://leetcode-cn.com/problems/2-keys-keyboard/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
    int minSteps(int n)
    {
        std::vector<int> dp(n + 1);
        int h = std::sqrt(n);
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = i;
            for (int j = 2; j <= h; ++j)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    int num = 3;

    Solution solution;
    auto min_steps = solution.minSteps(num);
    std::cout << "The solution of this problem is " << min_steps << std::endl;

    return 0;
}
