#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: coinChange.py
@Function: 零钱兑换 背包问题 - 动态规划
@Link: https://leetcode-cn.com/problems/coin-change/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-15
"""

from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0

        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1


# -----------------------------
if __name__ == "__main__":
    coins = [1, 2, 5]
    amount = 11

    solution = Solution()
    min_coins = solution.coinChange(coins, amount)
    print(f"The solutio of this problem is {min_coins}")
