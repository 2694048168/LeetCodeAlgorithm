#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: checkPossibility.py
@Function: 非递减数列 贪心策略各种情况下是否依然是最优解
@Link: https://leetcode-cn.com/problems/non-decreasing-array/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-06
"""

class Solution:
    def checkPossibility(self, nums):
        cnt = 0
        for i in range(len(nums)-1):
            x, y = nums[i], nums[i+1]
            if x > y:
                cnt += 1
                if cnt > 1:
                    return False
                if i > 0 and y < nums[i-1]:
                    nums[i+1] = x
        return True


# ---------------------------------
if __name__ == "__main__":
    # nums = [4,2,3]
    nums = [4,2,1]

    solution = Solution()
    check = solution.checkPossibility(nums)
    print(f"The solution of this problem is : {check}")