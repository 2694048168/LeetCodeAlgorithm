#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: uniquePaths.py
@Function: 不同路径
@Link: https://leetcode-cn.com/problems/unique-paths/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-31
"""

from typing import List
import math

# 动态规划
class Solution2:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[1] * n] + [[1] + [0] * (n - 1) for _ in range(m - 1)]
        print(f)
        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = f[i - 1][j] + f[i][j - 1]
        return f[m - 1][n - 1]


# 组合数学
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return math.comb(m + n - 2, n - 1)


# --------------------------
if __name__ == "__main__":
    m, n = 3, 2

    solution = Solution()
    unique_path = solution.uniquePaths(m, n)
    print(f"The solution of this problem is : {unique_path}")

