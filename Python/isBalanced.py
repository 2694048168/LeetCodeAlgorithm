#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isBalanced.py
@Function: 平衡二叉树 
@Link: https://leetcode-cn.com/problems/balanced-binary-tree/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-31
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def height(root: TreeNode) -> int:
            if not root:
                return 0
            leftHeight = height(root.left)
            rightHeight = height(root.right)
            if leftHeight == -1 or rightHeight == -1 or abs(leftHeight - rightHeight) > 1:
                return -1
            else:
                return max(leftHeight, rightHeight) + 1

        return height(root) >= 0


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
