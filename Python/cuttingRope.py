#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: cuttingRope.py
@Function: 剪绳子
@Link: https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-25
"""


import math


class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n - 1
        a, b = n // 3, n % 3
        if b == 0:
            return int(math.pow(3, a))
        if b == 1:
            return int(math.pow(3, a - 1) * 4)
        return int(math.pow(3, a) * 2)


# --------------------------------------
if __name__ == "__main__":
    number = 10

    solution = Solution()
    cutting_rose = solution.cuttingRope(number)
    print(f"The solution of this problem is {cutting_rose}")
