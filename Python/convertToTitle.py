#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: convertToTitle.py
@Function: Excel表列名称 数学问题
@Link: https://leetcode-cn.com/problems/excel-sheet-column-title/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-20
"""


class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = list()
        while columnNumber > 0:
            columnNumber -= 1
            ans.append(chr(columnNumber % 26 + ord("A")))
            columnNumber //= 26
        return "".join(ans[::-1])


# ----------------------------------
if __name__ == "__main__":
    # column_number = 1
    # column_number = 28
    # column_number = 701
    column_number = 2147483647

    solution = Solution()
    column_title = solution.convertToTitle(column_number)
    print(f"The solution of this problem is : {column_title}")
