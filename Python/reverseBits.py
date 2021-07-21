#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reverseBits.py
@Function: 颠倒给定的 32 位无符号整数的二进制位
@Link: https://leetcode-cn.com/problems/reverse-bits/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-21
"""


class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        n = (n >> 16) | (n << 16)
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8)
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4)
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2)
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1)
        return n


# -------------------------
if __name__ == "__main__":
    number = 43261596

    solution = Solution()
    binary_reverse_number = solution.reverseBits(number)
    print(f"The solution of this problem is {binary_reverse_number}")
