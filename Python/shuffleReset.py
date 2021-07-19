#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: shuffleReset.py
@Function: 打乱数组 数学问题
@Link: https://leetcode-cn.com/problems/shuffle-an-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-19
"""


import random


class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.original

    def shuffle(self):
        for i in range(len(self.array)):
            swap_idx = random.randrange(i, len(self.array))
            self.array[i], self.array[swap_idx] = self.array[swap_idx], self.array[i]
        return self.array


# ----------------------------------
if __name__ == "__main__":
    nums = [1, 2, 3]

    solution = Solution(nums)
    param_1 = solution.reset()
    param_2 = solution.shuffle()
    print("The solution of this problem is: ")
    print(f"The origin : {nums}")
    print(f"The reset : {param_1}")
    print(f"The shuffle : {param_2}")
