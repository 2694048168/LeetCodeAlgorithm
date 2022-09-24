#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: max_sub_array.py
@Function: 最大子数组和
@Link: https://leetcode.cn/problems/maximum-subarray/
@Python Version: 3.9.7
@Author: Wei Li (weili_yzzcq@163.com)
@Date: 2022-09-24
"""


class Solution:
    def maxSubArray(self, nums):
        pre_sum, max_sum = 0, nums[0]
        for _, value in enumerate(nums):
            pre_sum = max(pre_sum + value, value)
            max_sum = max(pre_sum, max_sum)

        return max_sum
        


# ----------------------------------
if __name__ == "__main__":
    nums_1 = [-2,1,-3,4,-1,2,1,-5,4]
    nums_2 = [5,4,-1,7,8]
    nums_3 = [1]

    solution = Solution()
    max_sum1 = solution.maxSubArray(nums_1)
    max_sum2 = solution.maxSubArray(nums_2)
    max_sum3 = solution.maxSubArray(nums_3)
    print(f"The solution of this problem is : {max_sum1}")
    print(f"The solution of this problem is : {max_sum2}")
    print(f"The solution of this problem is : {max_sum3}")
