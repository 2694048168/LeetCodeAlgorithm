#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: averageOfLevels.py
@Function: 二叉树的层平均值
@Link: https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-31
"""

import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        averages = list()
        queue = collections.deque([root])
        while queue:
            total = 0
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                total += node.val
                left, right = node.left, node.right
                if left:
                    queue.append(left)
                if right:
                    queue.append(right)
            averages.append(total / size)
        return averages


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
