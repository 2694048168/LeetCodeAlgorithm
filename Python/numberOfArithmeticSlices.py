#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: numberOfArithmeticSlices.py
@Function: 等差数列划分 动态规划 注意处理边界条件
@Link: https://leetcode-cn.com/problems/arithmetic-slices/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-13
"""


class Solution:
    def numberOfArithmeticSlices(self, nums):
        n = len(nums)
        if n < 3:
            return 0

        dp = [0]*n
        for i in range(2, n):
            if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]:
                dp[i] = dp[i - 1] + 1

        return sum(dp)


# ------------------------
if __name__ == "__main__":
    nums = [1, 2, 3, 4]

    solution = Solution()
    num_arithmetic_slices = solution.numberOfArithmeticSlices(nums)
    print(f"The solution of this problem is {num_arithmetic_slices}")
