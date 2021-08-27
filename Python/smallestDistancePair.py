#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: smallestDistancePair.py
@Function: 找出第 k 小的距离对
@Link: https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-27
"""

from typing import List


class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        min = 0
        max = nums[-1] - nums[0]
        while min < max:
            mid = (min + max) // 2
            count = 0
            l = 0
            for r in range(len(nums)):
                while l < r and nums[r] - nums[l] > mid:
                    l += 1
                count += r - l
            if count >= k:
                max = mid
            else:
                min = mid + 1
        return min


# --------------------------
if __name__ == "__main__":
    nums = [1, 6, 1]
    k = 3

    solution = Solution()
    smallest_distance = solution.smallestDistancePair(nums, k)
    print(f"The solution of this problem is : {smallest_distance}")
