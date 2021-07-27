#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findDuplicate.py
@Function: 寻找重复数
@Link: https://leetcode-cn.com/problems/find-the-duplicate-number
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""


from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = fast = cir_start = 0
        while True:
            fast = nums[nums[fast]]
            slow = nums[slow]
            if fast == slow:
                break

        while True:
            slow = nums[slow]
            cir_start = nums[cir_start]
            if cir_start == slow:
                return slow


# -------------------------
if __name__ == "__main__":
    # nums = [1,3,2,2,5,2,3,7]
    nums = [3,1,3,4,2]

    solution = Solution()
    find_duplicate = solution.findDuplicate(nums)
    print(f"The solution of this problem is {find_duplicate}")
