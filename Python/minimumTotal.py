#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minimumTotal.py
@Function: 三角形最小路径和
@Link: https://leetcode-cn.com/problems/triangle/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-31
"""


from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        f = [[0] * n for _ in range(2)]
        f[0][0] = triangle[0][0]

        for i in range(1, n):
            curr, prev = i % 2, 1 - i % 2
            f[curr][0] = f[prev][0] + triangle[i][0]
            for j in range(1, i):
                f[curr][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j]
            f[curr][i] = f[prev][i - 1] + triangle[i][i]

        return min(f[(n - 1) % 2])


# --------------------------
if __name__ == "__main__":
    triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]

    solution = Solution()
    mini_num_total = solution.minimumTotal(triangle)
    print(f"The solution of this problem is : {mini_num_total}")
