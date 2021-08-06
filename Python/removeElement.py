#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: removeElement.py
@Function: 移除元素
@Link: https://leetcode-cn.com/problems/remove-element/ 
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-06
"""

from typing import List

# 注意这些实现方法并没有改变元素的相对位置
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            if nums[left] == val:
                nums[left] = nums[right - 1]
                right -= 1
            else:
                left += 1
        return left


# --------------------------
if __name__ == "__main__":
    nums = [0,1,2,2,3,0,4,2]
    val = 2

    solution = Solution()
    num_list = solution.removeElement(nums, val)
    print(f"The solution of this problem is: {num_list}")
