#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: sortColors.py
@Function: 颜色分类
@Link: https://leetcode-cn.com/problems/sort-colors/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-10
"""


class Solution:
    def sortColors(self, nums):
        n = len(nums)
        p0, p2 = 0, n - 1
        i = 0
        while i <= p2:
            while i <= p2 and nums[i] == 2:
                nums[i], nums[p2] = nums[p2], nums[i]
                p2 -= 1
            if nums[i] == 0:
                nums[i], nums[p0] = nums[p0], nums[i]
                p0 += 1
            i += 1


# --------------------------
if __name__ == "__main__":
    nums = [2, 0, 2, 1, 1, 0]
    # nums = [2,0,1]

    solution = Solution()
    solution.sortColors(nums)
    print(f"The solution of this problem is : {nums}")
