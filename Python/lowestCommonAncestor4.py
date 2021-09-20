#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lowestCommonAncestor4.py
@Function: 二叉树的最近公共祖先
@Link: https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-20
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


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


# -------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
