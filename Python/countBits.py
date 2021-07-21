#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: countBits.py
@Function: 比特位计数
@Link: https://leetcode-cn.com/problems/counting-bits/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-21
"""


from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        bits = [0]
        highBit = 0
        for i in range(1, n + 1):
            if i & (i - 1) == 0:
                highBit = i
            bits.append(bits[i - highBit] + 1)
        return bits


# -------------------------
if __name__ == "__main__":
    # number = 5
    number = 2

    solution = Solution()
    bit_num = solution.countBits(number)
    print(f"The solution of this problem is {bit_num}")
