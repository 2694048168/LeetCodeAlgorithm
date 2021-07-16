/**
 * @File    : maxProfitFree.cpp
 * @Brief   : 买卖股票的最佳时机含手续费 动态规划
 * @Link    : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices, int fee)
    {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

// ------------------------------
int main(int argc, char **argv)
{

    std::vector<int> prices{1, 3, 2, 8, 4, 9};
    int fee = 2;

    Solution solution;
    auto max_profit = solution.maxProfit(prices, fee);
    std::cout << "The solution of this problem is " << max_profit << std::endl;

    return 0;
}
