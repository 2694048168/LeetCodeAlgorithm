#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: canCompleteCircuit.py
@Function: 加油站
@Link: https://leetcode-cn.com/problems/gas-station/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-24
"""

from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1

        n = len(gas)

        res = 0
        cur_sum = 0
        for i in range(n):
            cur_sum += gas[i] - cost[i]
            if cur_sum < 0:
                cur_sum = 0
                res = i + 1
        return res


# -------------------------
if __name__ == "__main__":
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]

    solution = Solution()
    check_jump = solution.canCompleteCircuit(gas, cost)
    print(f"The solution of this problem is {check_jump}")
