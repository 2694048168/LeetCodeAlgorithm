/**
 * @File    : maxProfitChanceCooldown.cpp
 * @Brief   : 最佳买卖股票时机含冷冻期 动态规划
 * @Link    : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        std::vector<int> buy(n), sell(n), s1(n), s2(n);
        s1[0] = buy[0] = -prices[0];
        sell[0] = s2[0] = 0;
        for (int i = 1; i < n; i++)
        {
            buy[i] = s2[i - 1] - prices[i];
            s1[i] = std::max(buy[i - 1], s1[i - 1]);
            sell[i] = std::max(buy[i - 1], s1[i - 1]) + prices[i];
            s2[i] = std::max(s2[i - 1], sell[i - 1]);
        }
        return std::max(sell[n - 1], s2[n - 1]);
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> prices{1, 2, 3, 0, 2};

    Solution solution;
    auto max_profit = solution.maxProfit(prices);
    std::cout << "The solution of this problem is " << max_profit << std::endl;

    return 0;
}
