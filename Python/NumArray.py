#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: NumArray.py
@Function: 区域和检索 - 数组不可变
@Link: https://leetcode-cn.com/problems/range-sum-query-immutable/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-26
"""


from typing import List


class NumArray:

    def __init__(self, nums: List[int]):
        self.sums = [0]
        _sums = self.sums

        for num in nums:
            _sums.append(_sums[-1] + num)

    def sumRange(self, i: int, j: int) -> int:
        _sums = self.sums
        return _sums[j + 1] - _sums[i]


# -------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
