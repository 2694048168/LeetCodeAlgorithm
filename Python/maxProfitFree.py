#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxProfitFree.py
@Function: 买卖股票的最佳时机含手续费  动态规划
@Link: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""

from typing import List

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        sell, buy = 0, -prices[0]
        for i in range(1, n):
            sell, buy = max(
                sell, buy + prices[i] - fee), max(buy, sell - prices[i])
        return sell


# -------------------------
if __name__ == "__main__":
    prices = [1, 3, 2, 8, 4, 9]
    fee = 2

    solution = Solution()
    max_profit = solution.maxProfit(prices, fee)
    print(f"The solution of this problem is {max_profit}")
