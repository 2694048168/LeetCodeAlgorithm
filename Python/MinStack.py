#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: MinStack.py
@Function: 最小栈
@Link: https://leetcode-cn.com/problems/min-stack/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-25
"""


import math


class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = [math.inf]

    def push(self, x: int) -> None:
        self.stack.append(x)
        self.min_stack.append(min(x, self.min_stack[-1]))

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


# --------------------------------------
if __name__ == "__main__":
    # Test on LeetCode online.
    pass
