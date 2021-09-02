#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: CQueue.py
@Function: 用两个栈实现队列
@Link: https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-02
"""


class CQueue:
    def __init__(self):
        self.A, self.B = [], []

    def appendTail(self, value: int) -> None:
        self.A.append(value)

    def deleteHead(self) -> int:
        if self.B:
            return self.B.pop()
        if not self.A:
            return -1
        while self.A:
            self.B.append(self.A.pop())
        return self.B.pop()


# ----------------------------------
# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
if __name__ == "__main__":
    # test on leetcode online.
    pass
