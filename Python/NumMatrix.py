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


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), (len(matrix[0]) if matrix else 0)
        self.sums = [[0] * (n + 1) for _ in range(m)]
        _sums = self.sums

        for i in range(m):
            for j in range(n):
                _sums[i][j + 1] = _sums[i][j] + matrix[i][j]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        _sums = self.sums

        total = sum(_sums[i][col2 + 1] - _sums[i][col1]
                    for i in range(row1, row2 + 1))
        return total


# -------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
