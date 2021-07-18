#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: trailingZeroes.py
@Function: 阶乘后的零 数学问题
@Link: https://leetcode-cn.com/problems/factorial-trailing-zeroes/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-18
"""


class Solution:
    def trailingZeroes(self, n: int) -> int:
        zero_count = 0
        while n > 0:
            n //= 5
            zero_count += n
        return zero_count


# ----------------------------------
if __name__ == "__main__":
    n = 12

    solution = Solution()
    num_zeros = solution.trailingZeroes(n)
    print(f"The solution of this problem is : {num_zeros}")
