#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxNumber.py
@Function: 拼接最大数
@Link: https://leetcode-cn.com/problems/create-maximum-number/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-25
"""

from typing import List


class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        m, n = len(nums1), len(nums2)
        maxSubsequence = [0] * k
        start, end = max(0, k - n), min(k, m)

        for i in range(start, end + 1):
            subsequence1 = self.getMaxSubsequence(nums1, i)
            subsequence2 = self.getMaxSubsequence(nums2, k - i)
            curMaxSubsequence = self.merge(subsequence1, subsequence2)
            if self.compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0:
                maxSubsequence = curMaxSubsequence

        return maxSubsequence

    def getMaxSubsequence(self, nums: List[int], k: int) -> int:
        stack = [0] * k
        top = -1
        remain = len(nums) - k

        for i, num in enumerate(nums):
            while top >= 0 and stack[top] < num and remain > 0:
                top -= 1
                remain -= 1
            if top < k - 1:
                top += 1
                stack[top] = num
            else:
                remain -= 1

        return stack

    def merge(self, subsequence1: List[int], subsequence2: List[int]) -> List[int]:
        x, y = len(subsequence1), len(subsequence2)
        if x == 0:
            return subsequence2
        if y == 0:
            return subsequence1

        mergeLength = x + y
        merged = list()
        index1 = index2 = 0

        for _ in range(mergeLength):
            if self.compare(subsequence1, index1, subsequence2, index2) > 0:
                merged.append(subsequence1[index1])
                index1 += 1
            else:
                merged.append(subsequence2[index2])
                index2 += 1

        return merged

    def compare(self, subsequence1: List[int], index1: int, subsequence2: List[int], index2: int) -> int:
        x, y = len(subsequence1), len(subsequence2)
        while index1 < x and index2 < y:
            difference = subsequence1[index1] - subsequence2[index2]
            if difference != 0:
                return difference
            index1 += 1
            index2 += 1

        return (x - index1) - (y - index2)


# -------------------------
if __name__ == "__main__":
    # nums1 = [6, 7]
    # nums2 = [6, 0, 4]
    # k = 5

    nums1 = [3, 4, 6, 5]
    nums2 = [9, 1, 2, 5, 8, 3]
    k = 5

    solution = Solution()
    max_number_order = solution.maxNumber(nums1, nums2, k)
    print(f"The solution of this problem is {max_number_order}")
