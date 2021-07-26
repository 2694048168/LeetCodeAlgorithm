#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: matrixReshape.py
@Function: 重塑矩阵
@Link: https://leetcode-cn.com/problems/reshape-the-matrix/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-26
"""

from typing import List


class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(nums), len(nums[0])
        if m * n != r * c:
            return nums

        ans = [[0] * c for _ in range(r)]
        for x in range(m * n):
            ans[x // c][x % c] = nums[x // n][x % n]

        return ans


# -------------------------
if __name__ == "__main__":
    nums = [[1, 2], [3, 4]]
    # r, c = 1, 4
    r, c = 2, 4

    solution = Solution()
    reshape_matrix = solution.matrixReshape(nums, r, c)
    print(f"The solutino of this problem is {reshape_matrix}")
