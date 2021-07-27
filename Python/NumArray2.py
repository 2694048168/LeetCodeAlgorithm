#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: NumArray2.py
@Function: 区域和检索 - 数组可修改
@Link: https://leetcode-cn.com/problems/range-sum-query-mutable/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-27
"""

from typing import List

# 线段树
class SegTree:
    def __init__(self, nums, function):
        self.nums = nums
        self.n = len(self.nums)
        self.tree = [0 for _ in range(4 * self.n)]
        self.function = function
        if self.n > 0:
            self._build(0, 0, self.n - 1)

    def update(self, ID, newValue):
        self.nums[ID] = newValue
        self._update(0, 0, self.n - 1, ID, newValue)

    def query(self, ql, qr):
        return self._query(0, 0, self.n - 1, ql, qr)

    def _build(self, root, l, r):
        if l == r:
            self.tree[root] = self.nums[r]
            return
        mid = (l + r) // 2
        left = 2 * root + 1
        right = 2 * root + 2
        self._build(left, l, mid)
        self._build(right, mid + 1, r)
        self.tree[root] = self.function(self.tree[left], self.tree[right])

    def _update(self, root, l, r, ID, newValue):
        if l == r == ID:
            self.tree[root] = newValue
            return
        mid = (l + r) // 2
        left = 2 * root + 1
        right = 2 * root + 2
        if ID <= mid:
            self._update(left, l, mid, ID, newValue)
        else:
            self._update(right, mid + 1, r, ID, newValue)
        self.tree[root] = self.function(self.tree[left], self.tree[right])

    def _query(self, root, l, r, ql, qr):
        if l == ql and r == qr:
            return self.tree[root]
        mid = l + r >> 1
        left = 2 * root + 1
        right = 2 * root + 2
        if qr <= mid:
            return self._query(left, l, mid, ql, qr)
        elif mid < ql:
            return self._query(right, mid + 1, r, ql, qr)
        else:
            return self.function(self._query(left, l, mid, ql, mid), self._query(right, mid + 1, r, mid + 1, qr))


class NumArray:

    def __init__(self, nums: List[int]):
        self.ST = SegTree(nums, lambda x, y: x + y)

    def update(self, index: int, val: int) -> None:
        self.ST.update(index, val)

    def sumRange(self, left: int, right: int) -> int:
        return self.ST.query(left, right)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
if __name__ == "__main__":
    # Test on LeetCode online.
    pass
