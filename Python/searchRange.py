#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: searchRange.py
@Function: 在排序数组中查找元素的第一个和最后一个位置
@Link: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-08
"""


class Solution:
    def searchRange(self, nums, target):
        # 二分查找，搜索左右边界
        if not nums:
            return [-1, -1]
        return [self._search_left(nums, target), self._search_right(nums, target)]

    def _search_left(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] == target:
                right = mid - 1                         # 改动这里，使搜索区间向左侧收缩
        if left >= len(nums) or nums[left] != target:   # 判断索引越界情况
            return -1
        return left

    def _search_right(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] == target:
                left = mid + 1                          # 改动这里，使搜索区间向右侧收缩
        if right < 0 or nums[right] != target:          # 判断索引越界情况
            return -1                                   
        return right


# -------------------------
if __name__ == "__main__":
    nums = [5,7,7,8,8,10]
    # target = 8
    target = 6

    solution = Solution()
    index_target = solution.searchRange(nums=nums, target=target)
    print(index_target)