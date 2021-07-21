#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: hammingDistance.py
@Function: 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目
@Link: https://leetcode-cn.com/problems/hamming-distance/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-21
"""


class Solution:
    def hammingDistance(self, x, y):
        return bin(x ^ y).count('1')


# -------------------------
if __name__ == "__main__":
    x, y = 1, 4
    # x, y = 3, 1

    solution = Solution()
    hamming_distance = solution.hammingDistance(x, y)
    print(f"The solution of this problem is {hamming_distance}")
