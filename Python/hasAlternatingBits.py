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
    def hasAlternatingBits(self, n: int) -> bool:
        flag = n & 1
        n = n >> 1
        while n > 0:
            if flag == n & 1:
                return False
            flag = n & 1
            n = n >> 1
        return True


# ------------------------
if __name__ == "__main__":
    # number = 5
    number = 7

    solution = Solution()
    check_alternate_bits = solution.hasAlternatingBits(number)
    print(f"The solution of this problem is {check_alternate_bits}")
