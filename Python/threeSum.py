#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: threeSum.py
@Function: 三数之和
@Link: https://leetcode-cn.com/problems/3sum/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-10
"""

from typing import List

# 排序 + 双指针策略 + 去重策略
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        num_list = len(nums)
        nums.sort()
        ans = list()

        for first_idx in range(num_list):
            if first_idx > 0 and nums[first_idx] == nums[first_idx - 1]:
                continue

            third_idx = num_list - 1
            target = -nums[first_idx]

            for second_idx in range(first_idx + 1, num_list):
                if second_idx > first_idx + 1 and nums[second_idx] == nums[second_idx - 1]:
                    continue

                while second_idx < third_idx and nums[second_idx] + nums[third_idx] > target:
                    third_idx -= 1

                if second_idx == third_idx:
                    break

                if nums[second_idx] + nums[third_idx] == target:
                    ans.append([nums[first_idx], nums[second_idx], nums[third_idx]])

        return ans


# -------------------------
if __name__ == "__main__":
    nums = [-1, 0, 1, 2, -1, -4]

    solution = Solution()
    three_sum_idx = solution.threeSum(nums)
    print(f"The solution of this problem is : {three_sum_idx}")
