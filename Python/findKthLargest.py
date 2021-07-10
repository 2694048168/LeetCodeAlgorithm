#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findKthLargest.py
@Function: 数组中的第K个最大元素  快速选择
@Link: https: // leetcode-cn.com/problems/kth-largest-element-in-an-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-10
"""

import random


class Solution:
    def findKthLargest(self, nums, k):
        def findTopKth(low, high):
            pivot = random.randint(low, high)
            nums[low], nums[pivot] = nums[pivot], nums[low]
            base = nums[low]
            i = low
            j = low + 1
            while j <= high:
                if nums[j] > base:
                    nums[i + 1], nums[j] = nums[j], nums[i + 1]
                    i += 1
                j += 1
            nums[low], nums[i] = nums[i], nums[low]
            if i == k - 1:
                return nums[i]
            elif i > k - 1:
                return findTopKth(low, i - 1)
            else:
                return findTopKth(i + 1, high)
        return findTopKth(0, len(nums) - 1)


# -------------------------
if __name__ == "__main__":
    # nums = [3, 2, 1, 5, 6, 4]
    # k = 2

    nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k = 4

    solution = Solution()
    kth_largest = solution.findKthLargest(nums, k)
    print(f"The solution of this problem is : {kth_largest}")
