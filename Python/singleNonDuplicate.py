#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: singleNonDuplicate.py
@Function: 有序数组中的单一元素
@Link: https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-09
"""

class Solution:
    def singleNonDuplicate(self, nums):
        low, high = 0, len(nums) - 1   
        while low < high:
            mid = low + (high - low) // 2
            halves_are_even = (high - mid) % 2 == 0
            if nums[mid + 1] == nums[mid]:
                if halves_are_even:
                    low = mid + 2
                else:
                    high = mid - 1
            elif nums[mid - 1] == nums[mid]:
                if halves_are_even:
                    high = mid - 2
                else:
                    low = mid + 1
            else:
                return nums[mid]
        return nums[low]


# 仅对偶数索引进行二分搜索
class Solution:
    def singleNonDuplicate(self, nums):
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if mid % 2 == 1:
                mid -= 1
            if nums[mid] == nums[mid + 1]:
                lo = mid + 2
            else:
                hi = mid
        return nums[lo]


# -------------------------
if __name__ == "__main__":
    nums = [1,1,2,3,3,4,4,8,8]
    # nums = [3,3,7,7,10,11,11]

    solution = Solution()
    odd_value = solution.singleNonDuplicate(nums)
    print(f"The solution of thiss problem is : {odd_value}")