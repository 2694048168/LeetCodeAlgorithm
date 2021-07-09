#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findMin.py
@Function: 寻找旋转排序数组中的最小值 II
@Link: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-09
"""

# 二分查找算法适合排序好的数组进行检索或查找
class Solution:
    def findMin(self, nums):    
        low, high = 0, len(nums) - 1
        while low < high:
            pivot = low + (high - low) // 2
            if nums[pivot] < nums[high]:
                high = pivot 
            elif nums[pivot] > nums[high]:
                low = pivot + 1
            else:
                high -= 1
        return nums[low]


# -------------------------
if __name__ == "__main__":
    nums = [1,3,5]
    # nums = [2,2,2,0,1]

    solution = Solution()
    value_min = solution.findMin(nums)
    print(f"The solution of this problem is : {value_min}")