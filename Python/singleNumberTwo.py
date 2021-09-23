#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: singleNumberTwo.py
@Function: 数组中数字出现的次数 II
@Link: https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-23
"""

from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        counts = [0] * 32
        for num in nums:
            for j in range(32):
                counts[j] += num & 1
                num >>= 1
        res, m = 0, 3
        for i in range(32):
            res <<= 1
            res |= counts[31 - i] % m
        return res if counts[31] % m == 0 else ~(res ^ 0xffffffff)


# ------------------------
if __name__ == "__main__":
    nums = [9, 1, 7, 9, 7, 9, 7]

    solution = Solution()
    single_number = solution.singleNumber(nums)
    print(f"The solution of this problem is {single_number}")
