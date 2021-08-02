#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lowestCommonAncestor2.py
@Function: 二叉树的最近公共祖先
@Link : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-02
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if not left:
            return right
        if not right:
            return left
        return root


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass
