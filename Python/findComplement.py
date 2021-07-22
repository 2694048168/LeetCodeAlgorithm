#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: hasAlternatingBits.py
@Function: 交替位二进制数
@Link: https://leetcode-cn.com/problems/binary-number-with-alternating-bits/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-22
"""


class Solution:
    def findComplement(self, num: int) -> int:
        return num ^ (2**(len(bin(num))-2)-1)


# ------------------------
if __name__ == "__main__":
    number = 5
    # number = 1

    solution = Solution()
    complement_number = solution.findComplement(number)
    print(f"The solution of this problem is {complement_number}")
