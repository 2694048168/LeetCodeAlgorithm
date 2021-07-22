#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: missingNumber.py
@Function: 丢失的数字
@Link: https://leetcode-cn.com/problems/missing-number/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-22
"""


class Solution:
    def missingNumber(self, nums):
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing


# ------------------------
if __name__ == "__main__":
    nums = [1, 2, 3, 4]

    solution = Solution()
    missing_number = solution.missingNumber(nums)
    print(f"The solution of this problem is {missing_number}")
