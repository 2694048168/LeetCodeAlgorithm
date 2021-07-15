#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lengthOfLIS.py
@Function: 最长递增子序列 动态规划
@Link: https://leetcode-cn.com/problems/longest-increasing-subsequence/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-15
"""


from typing import List


class Solution2:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = []
        for i in range(len(nums)):
            dp.append(1)
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        d = []
        for n in nums:
            if not d or n > d[-1]:
                d.append(n)
            else:
                l, r = 0, len(d) - 1
                loc = r
                while l <= r:
                    mid = (l + r) // 2
                    if d[mid] >= n:
                        loc = mid
                        r = mid - 1
                    else:
                        l = mid + 1
                d[loc] = n
        return len(d)


# --------------------------
if __name__ == "__main__":
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    # nums = [0, 1, 0, 3, 2, 3]
    # nums = [7, 7, 7, 7, 7, 7, 7]

    solution = Solution()
    max_length = solution.lengthOfLIS(nums)
    print(f"The solution of this problem is {max_length}")
