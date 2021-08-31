#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minCostClimbingStairs.py
@Function: 使用最小花费爬楼梯
@Link: https://leetcode-cn.com/problems/min-cost-climbing-stairs/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-31
"""

from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        prev = curr = 0
        for i in range(2, n + 1):
            nxt = min(curr + cost[i - 1], prev + cost[i - 2])
            prev, curr = curr, nxt
        return curr


# --------------------------
if __name__ == "__main__":
    cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]

    solution = Solution()
    min_cost_clim_stairs = solution.minCostClimbingStairs(cost)
    print(f"The solution of this problem is : {min_cost_clim_stairs}")
