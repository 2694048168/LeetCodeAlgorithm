#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: convert.py
@Function: Z 字形变换
@Link: https://leetcode-cn.com/problems/zigzag-conversion/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-16
"""


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        res = ["" for _ in range(numRows)]
        i, flag = 0, -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1:
                flag = -flag
            i += flag
        return "".join(res)


# ----------------------------------
if __name__ == "__main__":
    s = "PAYPALISHIRING"
    numRows = 4

    solution = Solution()
    convert_z = solution.convert(s, numRows)
    print(f"The solution of this problem is {convert_z}")
