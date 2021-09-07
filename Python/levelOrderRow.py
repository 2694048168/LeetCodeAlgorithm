#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: levelOrder.py
@Function: 从上到下打印二叉树
@Link: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-07
"""

from typing import List
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res, queue = [], collections.deque()
        queue.append(root)
        while queue:
            tmp = []
            for _ in range(len(queue)):
                node = queue.popleft()
                tmp.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(tmp)
        return res


# ------------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
