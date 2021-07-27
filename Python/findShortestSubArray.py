#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findShortestSubArray.py
@Function: 数组的度
@Link: https://leetcode-cn.com/problems/degree-of-an-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""


from typing import List


class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        mp = dict()

        for i, num in enumerate(nums):
            if num in mp:
                mp[num][0] += 1
                mp[num][2] = i
            else:
                mp[num] = [1, i, i]

        maxNum = minLen = 0
        for count, left, right in mp.values():
            if maxNum < count:
                maxNum = count
                minLen = right - left + 1
            elif maxNum == count:
                if minLen > (span := right - left + 1):
                    minLen = span

        return minLen


# -------------------------
if __name__ == "__main__":
    nums = [1,2,2,3,1,4,2]

    solution = Solution()
    subarray = solution.findShortestSubArray(nums)
    print(f"The solution of this problem is {subarray}")
