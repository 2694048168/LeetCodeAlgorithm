#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxCoins.py
@Function: 戳气球 分治算法策略 & 动态规划策略
@Link: https://leetcode-cn.com/problems/burst-balloons/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-17
"""


from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        val = [1] + nums + [1]

        # @lru_cache(None)
        def solve(left: int, right: int) -> int:
            if left >= right - 1:
                return 0

            best = 0
            for i in range(left + 1, right):
                total = val[left] * val[i] * val[right]
                total += solve(left, i) + solve(i, right)
                best = max(best, total)

            return best

        return solve(0, n + 1)


# dp
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        rec = [[0] * (n + 2) for _ in range(n + 2)]
        val = [1] + nums + [1]

        for i in range(n - 1, -1, -1):
            for j in range(i + 2, n + 2):
                for k in range(i + 1, j):
                    total = val[i] * val[k] * val[j]
                    total += rec[i][k] + rec[k][j]
                    rec[i][j] = max(rec[i][j], total)

        return rec[0][n + 1]


# ----------------------------------
if __name__ == "__main__":
    nums = [3,1,5,8]

    solution = Solution()
    max_coins = solution.maxCoins(nums)
    print(f"The solution of this problem is : {max_coins}")
