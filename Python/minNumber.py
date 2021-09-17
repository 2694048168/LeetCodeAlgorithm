#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minNumber.py
@Function: 把数组排成最小的数
@Link: https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-17
"""


from typing import List


class Solution:
    def minNumber(self, nums: List[int]) -> str:
        def quick_sort(l, r):
            if l >= r:
                return
            i, j = l, r
            while i < j:
                while strs[j] + strs[l] >= strs[l] + strs[j] and i < j:
                    j -= 1
                while strs[i] + strs[l] <= strs[l] + strs[i] and i < j:
                    i += 1
                strs[i], strs[j] = strs[j], strs[i]
            strs[i], strs[l] = strs[l], strs[i]
            quick_sort(l, i - 1)
            quick_sort(i + 1, r)

        strs = [str(num) for num in nums]
        quick_sort(0, len(strs) - 1)
        return ''.join(strs)


# -------------------------
if __name__ == "__main__":
    # nums = [3,30,34,5,9]
    nums = [10, 2]

    solution = Solution()
    min_number = solution.minNumber(nums)
    print(f"The solution of this problem is {min_number}")
