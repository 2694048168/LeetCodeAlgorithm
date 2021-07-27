#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: MyStack.py
@Function: 用队列实现栈
@Link: https://leetcode-cn.com/problems/implement-stack-using-queues/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""


from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ret = [-1] * n
        stk = list()

        for i in range(n * 2 - 1):
            while stk and nums[stk[-1]] < nums[i % n]:
                ret[stk.pop()] = nums[i % n]
            stk.append(i % n)
        
        return ret


# -------------------------
if __name__ == "__main__":
    nums = [1,2,1]

    solution = Solution()
    next_greater_element = solution.nextGreaterElements(nums)
    print(f"The solution of this problem is\n {next_greater_element}")
