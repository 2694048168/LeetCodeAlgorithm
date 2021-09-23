#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: singleNumbers.py
@Function: 数组中数字出现的次数
@Link: https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-23
"""


from typing import List
import functools


class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
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
    nums = [1, 2, 10, 4, 1, 4, 3, 3]

    solution = Solution()
    single_number = solution.singleNumbers(nums)
    print(f"The solution of this problem is {single_number}")
