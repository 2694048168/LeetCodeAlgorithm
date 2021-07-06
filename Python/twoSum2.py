#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: twoSum2.py
@Function: 两数之和 II - 输入有序数组
@Link: https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-06
"""

class Solution:
    def twoSum(self, numbers, target):
        left_index, right_index = 0, len(numbers) - 1
        while left_index < right_index:
            total_sum = numbers[left_index] + numbers[right_index]
            if total_sum == target:
                return [left_index + 1, right_index + 1]
            elif total_sum < target:
                left_index += 1
            else:
                right_index -= 1
        return [-1, -1]


# -------------------------------
if __name__ == "__main__":
    # ----------test case----------
    # numbers = [2,7,11,15]
    # target = 9

    # numbers = [2,3,4]
    # target = 6

    numbers = [-1,0]
    target = -1
    # ----------test case----------
    solution = Solution()
    list_index = solution.twoSum(numbers, target)
    print(f"The solution of this problem is : {list_index}")