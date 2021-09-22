#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: hammingWeight.py
@Function: 二进制中1的个数
@Link: https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-22
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        ret = 0
        while n:
            n &= n - 1
            ret += 1
        return ret


# -------------------------
if __name__ == "__main__":
    # number = 11
    # number = 128
    number = 4294967293

    solution = Solution()
    hamming_weight = solution.hammingWeight(number)
    print(f"The solution of this problem is {hamming_weight}")
