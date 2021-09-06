#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: minArray.py
@Function: 旋转数组的最小数字
@Link: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-06
"""


from typing import List


class Solution:
    def minArray(self, numbers: List[int]) -> int:
        low, high = 0, len(numbers) - 1
        while low < high:
            pivot = low + (high - low) // 2
            if numbers[pivot] < numbers[high]:
                high = pivot
            elif numbers[pivot] > numbers[high]:
                low = pivot + 1
            else:
                high -= 1
        return numbers[low]


# --------------------------
if __name__ == "__main__":
    # nums = [3, 4, 5, 1, 2]
    nums = [3, 4, 5, 0, 1, 2]

    solution = Solution()
    min_number_array = solution.minArray(nums)
    print(f"The solution of this proble is {min_number_array}")
