#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: splitArray.py
@Function: 分割数组的最大值
@Link: https://leetcode-cn.com/problems/split-array-largest-sum/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-25
"""


from typing import List


class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def check(x: int) -> bool:
            total, cnt = 0, 1
            for num in nums:
                if total + num > x:
                    cnt += 1
                    total = num
                else:
                    total += num
            return cnt <= m

        left = max(nums)
        right = sum(nums)
        while left < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid + 1

        return left


# -------------------------
if __name__ == "__main__":
    nums = [1,4,4]
    m = 3

    solution = Solution()
    split_array_result = solution.splitArray(nums, m)
    print(f"The solution of this problem is {split_array_result}")
