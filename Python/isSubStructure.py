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
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A and not B:
            return True
        if not B or not A:
            return False
        if A.val == B.val:
            if self.check(A, B):
                return True
        return self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)

    def check(self, node, target):
        if not target:
            return True
        if not node:
            return False
        if node.val == target.val:
            return self.check(node.left, target.left) and self.check(node.right, target.right)


# ----------------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
