#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: numSquares.py
@Function: 完全平方数 动态规划
@Link: https://leetcode-cn.com/problems/perfect-squares/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-14
"""


class Solution:
    def numSquares(self, n: int) -> int:
        '''版本一'''
        # 初始化
        nums = [i**2 for i in range(1, n + 1) if i**2 <= n]
        dp = [10**4]*(n + 1)
        dp[0] = 0
        # 遍历背包
        for j in range(1, n + 1):
            # 遍历物品
            for num in nums:
                if j >= num:
                    dp[j] = min(dp[j], dp[j - num] + 1)
        return dp[n]
    
    def numSquares1(self, n: int) -> int:
        '''版本二'''
        # 初始化
        nums = [i**2 for i in range(1, n + 1) if i**2 <= n]
        dp = [10**4]*(n + 1)
        dp[0] = 0
        # 遍历物品
        for num in nums:
            # 遍历背包
            for j in range(num, n + 1):
                dp[j] = min(dp[j], dp[j - num] + 1)
        return dp[n]


# -------------------------
if __name__ == "__main__":
    # n = 12
    n = 13

    solution = Solution()
    # num_sequares = solution.numSquares(n)
    num_sequares = solution.numSquares1(n)
    print(f"The solution of this problem is : {num_sequares}")
