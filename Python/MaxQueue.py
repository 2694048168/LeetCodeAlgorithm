#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: MaxQueue.py
@Function: 队列的最大值
@Link: https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-28
"""


import queue


class MaxQueue:

    def __init__(self):
        self.deque = queue.deque()
        self.queue = queue.Queue()

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1

    def push_back(self, value: int) -> None:
        while self.deque and self.deque[-1] < value:
            self.deque.pop()
        self.deque.append(value)
        self.queue.put(value)

    def pop_front(self) -> int:
        if not self.deque:
            return -1
        ans = self.queue.get()
        if ans == self.deque[0]:
            self.deque.popleft()
        return ans



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
# -------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
