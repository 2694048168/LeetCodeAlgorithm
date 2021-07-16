/**
 * @File    : maxProfitChance.cpp
 * @Brief   : 买卖股票的最佳时机 动态规划
 * @Link    : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
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
        int sell = 0, buy = INT_MIN;
        for (int i = 0; i < prices.size(); ++i)
        {
            buy = std::max(buy, -prices[i]);
            sell = std::max(sell, buy + prices[i]);
        }
        return sell;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // std::vector<int> prices{7, 1, 5, 3, 6, 4};
    std::vector<int> prices{7, 6, 4, 3, 1};

    Solution solution;
    auto max_profit = solution.maxProfit(prices);
    std::cout << "The solution of this problem is " << max_profit << std::endl;

    return 0;
}
