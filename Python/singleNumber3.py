#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: singleNumber3.py
@Function: 只出现一次的数字 III
@Link: https://leetcode-cn.com/problems/single-number-iii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-22
"""


from typing import List
import functools


class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        ret = functools.reduce(lambda x, y: x ^ y, nums)
        div = 1
        while div & ret == 0:
            div <<= 1
        a, b = 0, 0
        for n in nums:
            if n & div:
                a ^= n
            else:
                b ^= n
        return [a, b]


# ------------------------
if __name__ == "__main__":
    nums = [1,2,1,3,2,5]

    solution = Solution()
    single_nums = solution.singleNumber(nums)
    print(f"The solution of this problem is {single_nums}")
