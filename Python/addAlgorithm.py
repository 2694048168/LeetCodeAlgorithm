#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: addAlgorithm.py
@Function: 不用加减乘除做加法
@Link: https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-22
"""


class Solution2:
    def add(self, a: int, b: int) -> int:
        x = 0xffffffff
        a, b = a & x, b & x
        while b != 0:
            a, b = (a ^ b), (a & b) << 1 & x
        return a if a <= 0x7fffffff else ~(a ^ x)


class Solution:
    def add(self, a: int, b: int) -> int:
        x = 0xffffffff
        a, b = a & x, b & x
        while b != 0:
            a, b = (a ^ b), (a & b) << 1 & x
        return a if a <= 0x7fffffff else ~(a ^ x)


# -------------------------
if __name__ == "__main__":
    a, b = 1, 1

    solution = Solution()
    result_add = solution.add(a, b)
    print(f"The solution of this problem is {result_add}")
