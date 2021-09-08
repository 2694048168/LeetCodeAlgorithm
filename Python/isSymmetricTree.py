#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isSymmetricTree.py
@Function: 对称的二叉树
@Link: https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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
    def isSymmetric(self, root: TreeNode) -> bool:
        def recur(L, R):
            if not L and not R:
                return True
            if not L or not R or L.val != R.val:
                return False
            return recur(L.left, R.right) and recur(L.right, R.left)

        return recur(root.left, root.right) if root else True


# ----------------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
