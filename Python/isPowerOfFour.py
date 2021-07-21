#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isPowerOfFour.py
@Function: 4的幂
@Link: https://leetcode-cn.com/problems/power-of-four/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-21
"""


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0 and (n & 0xaaaaaaaa) == 0


# -------------------------
if __name__ == "__main__":
    # number = 16
    number = 6

    solution = Solution()
    check_power_four = solution.isPowerOfFour(number)
    print(f"The solution of this problem is {check_power_four}")
