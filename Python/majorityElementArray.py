#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: majorityElementArray.py
@Function: 数组中出现次数超过一半的数字
@Link: https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-24
"""


from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        def majority_element_rec(lo, hi) -> int:
            # base case; the only element in an array of size 1 is the majority
            # element.
            if lo == hi:
                return nums[lo]

            # recurse on left and right halves of this slice.
            mid = (hi - lo) // 2 + lo
            left = majority_element_rec(lo, mid)
            right = majority_element_rec(mid + 1, hi)

            # if the two halves agree on the majority element, return it.
            if left == right:
                return left

            # otherwise, count each element and return the "winner".
            left_count = sum(1 for i in range(lo, hi + 1) if nums[i] == left)
            right_count = sum(1 for i in range(lo, hi + 1) if nums[i] == right)

            return left if left_count > right_count else right

        return majority_element_rec(0, len(nums) - 1)


# ----------------------------------
if __name__ == "__main__":
    nums = [1, 2, 3, 2, 2, 2, 5, 4, 2]

    solution = Solution()
    majority_number = solution.majorityElement(nums)
    print(f"The solution of this problem is : {majority_number}")
