#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxProfitChance.py
@Function: 买卖股票的最佳时机 动态规划
@Link: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        inf = int(1e9)
        minprice = inf
        maxprofit = 0
        for price in prices:
            maxprofit = max(price - minprice, maxprofit)
            minprice = min(price, minprice)
        return maxprofit


# ---------------------------
if __name__ == "__main__":
    prices = [7, 1, 5, 3, 6, 4]

    solution = Solution()
    max_profit = solution.maxProfit(prices)
    print(f"The solution of this problem is {max_profit}")
