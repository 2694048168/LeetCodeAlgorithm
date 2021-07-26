#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: subarraySum.py
@Function: 和为K的子数组
@Link: https://leetcode-cn.com/problems/subarray-sum-equals-k/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-26
"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        total = 0
        res = 0
        count = {}
        for num in nums:
            total += num
            if total == k:
                res += 1
            if total - k in count:
                res += count[total - k]
            count[total] = count.get(total, 0) + 1
        return res


# -------------------------
if __name__ == "__main__":
    nums, k = [1,1,1], 2

    solution = Solution()
    num_subarray = solution.subarraySum(nums, k)
    print(f"The solutino of this problem is {num_subarray}")
