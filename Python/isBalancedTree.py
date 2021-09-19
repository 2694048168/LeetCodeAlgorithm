#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxDepthTree.py
@Function: 二叉树的深度 
@Link: https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-09-19
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


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
