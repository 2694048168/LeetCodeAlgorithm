#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: smallestRange.py
@Function: 最小区间
@Link: https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-30
"""

from typing import List
import heapq


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        rangeLeft, rangeRight = -10**9, 10**9
        maxValue = max(vec[0] for vec in nums)
        priorityQueue = [(vec[0], i, 0) for i, vec in enumerate(nums)]
        heapq.heapify(priorityQueue)

        while True:
            minValue, row, idx = heapq.heappop(priorityQueue)
            if maxValue - minValue < rangeRight - rangeLeft:
                rangeLeft, rangeRight = minValue, maxValue
            if idx == len(nums[row]) - 1:
                break
            maxValue = max(maxValue, nums[row][idx + 1])
            heapq.heappush(priorityQueue, (nums[row][idx + 1], row, idx + 1))

        return [rangeLeft, rangeRight]


# -----------------------------
if __name__ == "__main__":
    nums = [[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]]

    solution = Solution()
    smallest_range = solution.smallestRange(nums)
    print(f"The solutio of this problem is {smallest_range}")
