#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minPatches.py
@Function: 按要求补齐数组
@Link: https://leetcode-cn.com/problems/patching-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-25
"""


from typing import List


class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        patches, x = 0, 1
        length, index = len(nums), 0

        while x <= n:
            if index < length and nums[index] <= x:
                x += nums[index]
                index += 1
            else:
                x <<= 1
                patches += 1

        return patches


# -------------------------
if __name__ == "__main__":
    # nums, n = [1, 5, 10], 20
    nums, n = [1, 2, 2], 5

    solution = Solution()
    min_patches = solution.minPatches(nums, n)
    print(f"The solution of this problem is {min_patches}")
