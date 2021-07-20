#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: addBinary.py
@Function: 二进制求和 数学问题
@Link: https://leetcode-cn.com/problems/add-binary/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-20
"""

# 位运算操作
class Solution:
    def addBinary(self, a, b) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        return bin(x)[2:]


# ----------------------------------
if __name__ == "__main__":
    # a, b = "11", "1"
    a, b = "1010", "1011"

    solution = Solution()
    add_binary = solution.addBinary(a, b)
    print(f"The solution of this problem is : {add_binary}")
