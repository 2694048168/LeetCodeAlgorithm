#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: nextPermutation.py
@Function: 下一个排列
@Link: https://leetcode-cn.com/problems/next-permutation/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-27
"""


from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while j >= 0 and nums[i] >= nums[j]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        left, right = i + 1, len(nums) - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1


# --------------------------
if __name__ == "__main__":
    nums = [3, 2, 1]

    solution = Solution()
    print(f"Processing before: {nums}")
    solution.nextPermutation(nums)
    print(f"Processing after: {nums}")
