#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxProfitChance2.py
@Function: 买卖股票的最佳时机 IV 动态规划
@Link: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def maxProfit(self, k: int, prices) -> int:
        if not prices:
            return 0

        n = len(prices)
        k = min(k, n // 2)
        buy = [0] * (k + 1)
        sell = [0] * (k + 1)

        buy[0], sell[0] = -prices[0], 0
        for i in range(1, k + 1):
            buy[i] = sell[i] = float("-inf")

        for i in range(1, n):
            buy[0] = max(buy[0], sell[0] - prices[i])
            for j in range(1, k + 1):
                buy[j] = max(buy[j], sell[j] - prices[i])
                sell[j] = max(sell[j], buy[j - 1] + prices[i])

        return max(sell)


# --------------------------
if __name__ == "__main__":
    k = 2
    prices = [2, 4, 1]

    solution = Solution()
    max_profit = solution.maxProfit(k, prices)
    print(f"The solution of this problem is {max_profit}")
