#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: permuteUnique.py
@Function: 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
@Link: https://leetcode-cn.com/problems/permutations-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-12
"""


class Solution:
    def permuteUnique(self, nums):
        nums.sort()
        self.res = []
        check = [0 for i in range(len(nums))]

        self.backtrack([], nums, check)
        return self.res

    def backtrack(self, sol, nums, check):
        if len(sol) == len(nums):
            self.res.append(sol)
            return

        for i in range(len(nums)):
            if check[i] == 1:
                continue
            if i > 0 and nums[i] == nums[i-1] and check[i-1] == 0:
                continue
            check[i] = 1
            self.backtrack(sol+[nums[i]], nums, check)
            check[i] = 0


# -------------------------
if __name__ == "__main__":
    # nums = [1, 1, 2]
    nums = [1, 3, 2]

    solution = Solution()
    permute_unique_list = solution.permuteUnique(nums=nums)
    print(f"The solution of this problem is : {permute_unique_list}")
