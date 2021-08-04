#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: removeDuplicates.py
@Function: 删除有序数组中的重复项
@Link: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-04
"""


from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length_list = len(nums)
        if not length_list:
            return 0

        # 双指针策略
        fast = slow = 1
        while fast < length_list:
            if nums[fast] != nums[fast - 1]:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1

        return slow


# --------------------------
if __name__ == "__main__":
    # nums = [1, 1, 2]
    nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

    solution = Solution()
    num_duplicate_list = solution.removeDuplicates(nums)
    print(f"The length of original list is {len(nums)}")
    print(f"The length of remove duplicate list is {num_duplicate_list}")
