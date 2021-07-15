/**
 * @File    : coinChange.cpp
 * @Brief   : 零钱兑换 背包问题
 * @Link    : https://leetcode-cn.com/problems/coin-change/
 * @Author  : Wei Li
 * @Date    : 2021-07-15
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        if (coins.empty())
            return -1;

        std::vector<int> dp(amount + 1, amount + 2);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (const int &coin : coins)
            {
                if (i >= coin)
                {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 2 ? -1 : dp[amount];
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> coins{1, 2, 5};
    int amount = 11;

    Solution solution;
    auto min_coins = solution.coinChange(coins, amount);
    std::cout << "The solution of this problem is " << min_coins << std::endl;

    return 0;
}
