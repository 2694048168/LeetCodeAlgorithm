#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: povit_index.py
@Function: 寻找数组的中心下标
@Link: https://leetcode.cn/problems/find-pivot-index/
@Python Version: 3.9.7
@Author: Wei Li (weili_yzzcq@163.com)
@Date: 2022-09-23
"""


class Solution:
    # def pivotIndex(self, nums: List[int]) -> int:
    def pivotIndex(self, nums):
        total_sum = sum(nums)
        left_sum = 0
        for idx, element in enumerate(nums):
            # product_sum_right = product_sum_total - product_sum_left - nums[idx]
            if (total_sum - 2 * left_sum) == nums[idx]:
                return idx
            left_sum += element
        return -1


# ----------------------------------
if __name__ == "__main__":
    nums_0 = [1, 7, 3, 6, 5, 6]
    nums_1 = [1, 2, 3]
    nums_2 = [2, 1, -1]

    solution = Solution()
    povit_index_0 = solution.pivotIndex(nums_0) # True=3
    povit_index_1 = solution.pivotIndex(nums_1) # True=-1
    povit_index_2 = solution.pivotIndex(nums_2) # TRue=0
    print(f"The solution of this problem is : {povit_index_0}")
    print(f"The solution of this problem is : {povit_index_1}")
    print(f"The solution of this problem is : {povit_index_2}")
