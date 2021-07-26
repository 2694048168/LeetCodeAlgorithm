#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: longestConsecutive.py
@Function: 最长连续序列
@Link: https://leetcode-cn.com/problems/longest-consecutive-sequence/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-26
"""


from typing import List


class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak


# -------------------------
if __name__ == "__main__":
    # nums = [100, 4, 200, 1, 3, 2]
    nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

    solution = Solution()
    longest_consecutive = solution.longestConsecutive(nums)
    print(f"The solution of this problem is {longest_consecutive}")
