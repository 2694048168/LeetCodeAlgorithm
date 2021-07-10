/**
 * @File    : maxProfit.cpp
 * @Brief   : 买卖股票的最佳时机 II 贪心策略
 * @Link    : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-06
*/

#include <iostream>
#include <vector>
#include <memory>

// -----------------
class Solution
{
public:
    size_t maxProfit(std::vector<int>& prices)
    {
        size_t ans = 0;
        for (size_t i = 1; i < prices.size(); ++i)
        {
            ans += std::max(0, prices[i] - prices[i - 1]);
        }

        return ans;
    }
};


// ------------------------------
int main(int argc, char** argv)
{
    // std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::vector<int> prices = {1, 2, 3, 4, 5};

    // auto solution = Solution();
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    size_t max_profit = solution->maxProfit(prices);
    // size_t max_profit = solution.maxProfit(prices);
    std::cout << "The solution of this problem is : " << max_profit << std::endl;

    return 0;
}
