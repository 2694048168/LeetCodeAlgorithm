#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: myPow.py
@Function: 数值的整数次方
@Link : https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-21
"""


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        res = 1
        if n < 0:
            x, n = 1 / x, -n
        while n:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        return res


# ------------------------------
if __name__ == "__main__":
    x = 2.0000
    n = 10

    solution = Solution()
    my_pow = solution.myPow(x, n)
    print(f"The solution of this problem is {my_pow}")
