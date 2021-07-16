/**
 * @File    : maxProfitChance2.cpp
 * @Brief   : 买卖股票的最佳时机 IV 动态规划
 * @Link    : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // 主函数
    int maxProfit(int k, std::vector<int> &prices)
    {
        int days = prices.size();
        if (days < 2)
        {
            return 0;
        }
        if (k >= days)
        {
            return maxProfitUnlimited(prices);
        }
        std::vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < days; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                buy[j] = std::max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = std::max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
    // 辅函数
    int maxProfitUnlimited(std::vector<int> prices)
    {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};

// ----------------------------------
int main(int argc, char **argv)
{
    int k = 2;
    // std::vector<int> prices{2, 4, 1};
    std::vector<int> prices{3, 2, 6, 5, 0, 3};

    Solution solution;
    auto max_profit = solution.maxProfit(k, prices);
    std::cout << "The solution of this problem is " << max_profit << std::endl;

    return 0;
}
