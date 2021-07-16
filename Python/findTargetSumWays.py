#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findTargetSumWays.py
@Function: 目标和  动态规划
@Link: https://leetcode-cn.com/problems/target-sum/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-16
"""


class Solution:
    def findTargetSumWays(self, nums, S) -> int:
        sumAll = sum(nums)
        if S > sumAll or (S + sumAll) % 2:
            return 0
        target = (S + sumAll) // 2

        dp = [0] * (target + 1)
        dp[0] = 1

        for num in nums:
            for j in range(target, num - 1, -1):
                dp[j] = dp[j] + dp[j - num]
        return dp[-1]


# -------------------------
if __name__ == "__main__":
    nums = [1, 1, 1, 1, 1]
    target = 3

    solution = Solution()
    sum_ways = solution.findTargetSumWays(nums, target)
    print(f"The solution of this problem is {sum_ways}")
