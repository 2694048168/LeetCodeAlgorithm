#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: inorderTraversal.py
@Function: 二叉树的中序遍历
@Link : https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-02
"""

from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        WHITE, GRAY = 0, 1
        res = []
        stack = [(WHITE, root)]
        while stack:
            color, node = stack.pop()
            if node is None:
                continue
            if color == WHITE:
                stack.append((WHITE, node.right))
                stack.append((GRAY, node))
                stack.append((WHITE, node.left))
            else:
                res.append(node.val)
        return res


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass
