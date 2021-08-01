#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isSubtree.py
@Function: 另一棵树的子树
@Link: https://leetcode-cn.com/problems/subtree-of-another-tree/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-01
"""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        if not s and not t:
            return True
        if not s or not t:
            return False
        return self.isSameTree(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def isSameTree(self, s, t):
        if not s and not t:
            return True
        if not s or not t:
            return False
        return s.val == t.val and self.isSameTree(s.left, t.left) and self.isSameTree(s.right, t.right)


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
