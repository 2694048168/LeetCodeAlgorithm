#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxSlidingWindow.py
@Function: 滑动窗口最大值
@Link: https://leetcode-cn.com/problems/sliding-window-maximum/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-26
"""

from typing import List
import collections

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        q = collections.deque()
        for i in range(k):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)

        ans = [nums[q[0]]]
        for i in range(k, n):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            while q[0] <= i - k:
                q.popleft()
            ans.append(nums[q[0]])

        return ans


# -------------------------
if __name__ == "__main__":
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3

    solution = Solution()
    max_slide_window = solution.maxSlidingWindow(nums, k)
    print(f"The solution of this problem is {max_slide_window}")
