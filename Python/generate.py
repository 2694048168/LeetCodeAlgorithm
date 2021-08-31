#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: generate.py
@Function: 杨辉三角
@Link: https://leetcode-cn.com/problems/pascals-triangle/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-31
"""


from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = list()
        for i in range(numRows):
            row = list()
            for j in range(0, i + 1):
                if j == 0 or j == i:
                    row.append(1)
                else:
                    row.append(ret[i - 1][j] + ret[i - 1][j - 1])
            ret.append(row)
        return ret


# --------------------------
if __name__ == "__main__":
    numRows = 5

    solution = Solution()
    generate_ranger = solution.generate(numRows)
    print(f"The solution of this problem is : \n{generate_ranger}")
