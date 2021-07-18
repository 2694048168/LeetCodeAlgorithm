#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: addStrings.py
@Function: 字符串相加 数学问题
@Link: https://leetcode-cn.com/problems/add-strings/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-18
"""


class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ""
        i, j, carry = len(num1) - 1, len(num2) - 1, 0
        while i >= 0 or j >= 0:
            n1 = int(num1[i]) if i >= 0 else 0
            n2 = int(num2[j]) if j >= 0 else 0
            tmp = n1 + n2 + carry
            carry = tmp // 10
            res = str(tmp % 10) + res
            i, j = i - 1, j - 1
        return "1" + res if carry else res


# ----------------------------------
if __name__ == "__main__":
    num1 = "99"
    num2 = "1"

    solution = Solution()
    add_sum = solution.addStrings(num1, num2)
    print(f"The solution of this problem is : {add_sum}")
