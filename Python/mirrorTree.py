#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isSubStructure.py
@Function: 树的子结构
@Link: https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-08
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root

        left = self.mirrorTree(root.left)
        right = self.mirrorTree(root.right)
        root.left, root.right = right, left
        return root


# ----------------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
