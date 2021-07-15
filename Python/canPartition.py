#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: canPartition.py
@Function: 分割等和子集 背包问题 —— 动态规划
@Link: https://leetcode-cn.com/problems/partition-equal-subset-sum/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-15
"""

# Reference <<LeetCode 101: A LeetCode Grinding Guide (C++ Version)>>
# 7.6 背包问题

from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 2:
            return False

        total = sum(nums)
        if total % 2 != 0:
            return False

        target = total // 2
        dp = [True] + [False] * target
        for i, num in enumerate(nums):
            for j in range(target, num - 1, -1):
                dp[j] |= dp[j - num]

        return dp[target]


# --------------------------
if __name__ == "__main__":
    # nums = [1, 5, 11, 5]
    nums = [1, 2, 3, 5]

    solution = Solution()
    check_partition = solution.canPartition(nums)
    print(f"The solution of this problem is {check_partition}")
