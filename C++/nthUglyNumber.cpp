/**
 * @File    : nthUglyNumber.cpp
 * @Brief   : 丑数
 * @Link    : https://leetcode-cn.com/problems/chou-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-30
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        std::vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++)
        {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = std::min(std::min(num2, num3), num5);
            if (dp[i] == num2)
            {
                p2++;
            }
            if (dp[i] == num3)
            {
                p3++;
            }
            if (dp[i] == num5)
            {
                p5++;
            }
        }
        return dp[n];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int number = 10;

    Solution solution;
    auto n_order_uglyNumber = solution.nthUglyNumber(number);
    std::cout << "The solution of this problem is " << n_order_uglyNumber << std::endl;

    return 0;
}
