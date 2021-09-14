#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: exchange.py
@Function: 调整数组顺序使奇数位于偶数前面
@Link: https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/ 
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-14
"""

from typing import List


class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            while i < j and nums[i] & 1 == 1:
                i += 1
            while i < j and nums[j] & 1 == 0:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        return nums


# -----------------------------------
if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5]

    solution = Solution()
    exchange_even_odd = solution.exchange(nums)
    print(f"The solution of this problem is : {exchange_even_odd}")
