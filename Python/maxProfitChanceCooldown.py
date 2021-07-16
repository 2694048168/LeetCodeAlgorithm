#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxProfitChanceCooldown.py
@Function: 最佳买卖股票时机含冷冻期 动态规划
@Link: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def maxProfit(self, prices) -> int:
        if not prices:
            return 0

        n = len(prices)
        f0, f1, f2 = -prices[0], 0, 0
        for i in range(1, n):
            newf0 = max(f0, f2 - prices[i])
            newf1 = f0 + prices[i]
            newf2 = max(f1, f2)
            f0, f1, f2 = newf0, newf1, newf2

        return max(f1, f2)


# --------------------------
if __name__ == "__main__":
    prices = [1, 2, 3, 0, 2]

    solution = Solution()
    max_profit = solution.maxProfit(prices)
    print(f"The solution of this problem is {max_profit}")
