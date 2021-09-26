#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: validateStackSequences.py
@Function: 栈的压入、弹出序列
@Link: https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-26
"""


from typing import List


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack, i = [], 0
        for num in pushed:
            stack.append(num)  # num 入栈
            while stack and stack[-1] == popped[i]:  # 循环判断与出栈
                stack.pop()
                i += 1
        return not stack


# --------------------------
if __name__ == "__main__":
    pushed = [1, 2, 3, 4, 5]
    popped = [4, 3, 5, 1, 2]

    solution = Solution()
    valid_stack_seq = solution.validateStackSequences(pushed, popped)
    print(f"The solution of this problem is {valid_stack_seq}")
