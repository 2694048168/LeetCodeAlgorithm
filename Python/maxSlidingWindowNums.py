#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxSlidingWindowNums.py
@Function: 动窗口的最大值
@Link: https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-28
"""


from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        m = - float('inf')
        res = []
        for i in range(k):
            m = max(m, nums[i])
        res.append(m)
        i += 1
        while i < len(nums):
            m = max(m, nums[i])
            if nums[i-k] == m:
                m = max(nums[i-k+1:i+1])
            res.append(m)
            i += 1
        return res


# -------------------------
if __name__ == "__main__":
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3

    solution = Solution()
    max_slide_window = solution.maxSlidingWindow(nums, k)
    print(f"The solution of this problem is {max_slide_window}")
