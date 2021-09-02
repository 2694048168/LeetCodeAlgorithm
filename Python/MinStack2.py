#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: MinStack2.py
@Function: 包含min函数的栈
@Link: https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-02
"""


class MinStack:
    def __init__(self):
        self.A, self.B = [], []

    def push(self, x: int) -> None:
        self.A.append(x)
        if not self.B or self.B[-1] >= x:
            self.B.append(x)

    def pop(self) -> None:
        if self.A.pop() == self.B[-1]:
            self.B.pop()

    def top(self) -> int:
        return self.A[-1]

    def min(self) -> int:
        return self.B[-1]


# ----------------------------------
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
if __name__ == "__main__":
    # test on leetcode online.
    pass
