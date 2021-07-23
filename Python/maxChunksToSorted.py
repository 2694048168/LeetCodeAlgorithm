#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxChunksToSorted.py
@Function: 最多能完成排序的块
@Link: https://leetcode-cn.com/problems/max-chunks-to-make-sorted/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-23
"""

from typing import List


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans = 0
        cur_max = 0
        for i in range(len(arr)):
            if arr[i] > cur_max:
                cur_max = arr[i]
            if cur_max == i:
                ans += 1
        return ans


# --------------------------------------
if __name__ == "__main__":
    arr = [4,3,2,1,0]

    solution = Solution()
    max_arr_sorted = solution.maxChunksToSorted(arr)
    print(f"The solution of this problem is : {max_arr_sorted}")
