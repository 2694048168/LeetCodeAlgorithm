#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: TinvertTreerie.py
@Function: 翻转二叉树
@Link: https://leetcode-cn.com/problems/invert-binary-tree/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-01
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root

        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        root.left, root.right = right, left
        return root


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
