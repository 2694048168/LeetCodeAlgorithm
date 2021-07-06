#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxProfit.py
@Function: 买卖股票的最佳时机 II 贪心策略
@Link: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-06
"""

# -------------------------
class Solution:
    def maxProfit(self, prices):
        profit = 0
        for i in range(1, len(prices)):
            profit += max(0, prices[i] - prices[i -1])

        return profit


# ----------------------------
if __name__ == "__main__":
    # prices = [7,1,5,3,6,4]
    prices = [1,2,3,4,5]

    solution = Solution()
    max_profit = solution.maxProfit(prices)
    print(f"The solution of this problem is : {max_profit}")