#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxSum.py
@Function: 最大得分
@Link: https://leetcode-cn.com/problems/get-the-maximum-score/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-27
"""


from typing import List


class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        mod = 10**9 + 7
        m, n = len(nums1), len(nums2)
        best1 = best2 = 0
        i = j = 0
        while i < m or j < n:
            if i < m and j < n:
                if nums1[i] < nums2[j]:
                    best1 += nums1[i]
                    i += 1
                elif nums1[i] > nums2[j]:
                    best2 += nums2[j]
                    j += 1
                else:
                    best = max(best1, best2) + nums1[i]
                    best1 = best2 = best
                    i += 1
                    j += 1
            elif i < m:
                best1 += nums1[i]
                i += 1
            elif j < n:
                best2 += nums2[j]
                j += 1

        return max(best1, best2) % mod


# --------------------------
if __name__ == "__main__":
    nums1 = [1, 2, 3, 4, 5]
    nums2 = [6, 7, 8, 9, 10]

    solution = Solution()
    max_sum = solution.maxSum(nums1, nums2)
    print(f"The solution of this problem is : {max_sum}")
