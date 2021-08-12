#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: firstMissingPositive.py
@Function: 缺失的第一个正数
@Link: https://leetcode-cn.com/problems/first-missing-positive
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-12
"""

from typing import List

# 哈希表
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if nums[i] <= 0:
                nums[i] = n + 1

        for i in range(n):
            num = abs(nums[i])
            if num <= n:
                nums[num - 1] = -abs(nums[num - 1])

        for i in range(n):
            if nums[i] > 0:
                return i + 1

        return n + 1


# 置换
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1


# -------------------------
if __name__ == "__main__":
    # nums = [1, 1, 12, 2, 0]
    # nums = [3, 4, -1, 1]
    nums = [7, 8, 9, 11, 12]

    solution = Solution()
    first_missing_positive = solution.firstMissingPositive(nums)
    print(f"The solution of this problem is {first_missing_positive}")
