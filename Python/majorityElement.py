#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: majorityElement.py
@Function: 多数元素 数学问题
@Link: https://leetcode-cn.com/problems/majority-element/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-20
"""


from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate


# ----------------------------------
if __name__ == "__main__":
    nums = [3, 2, 3]
    # nums = [2, 2, 1, 1, 1, 2, 2]

    solution = Solution()
    majority_element = solution.majorityElement(nums)
    print(f"The solution of this problem is : {majority_element}")
