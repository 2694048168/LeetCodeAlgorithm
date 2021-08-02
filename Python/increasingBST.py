#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: increasingBST.py
@Function: 递增顺序搜索树
@Link : https://leetcode-cn.com/problems/increasing-order-search-tree/
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


class Solution(object):
    def increasingBST(self, root):
        dummy = TreeNode(-1)
        self.prev = dummy
        self.inOrder(root)
        return dummy.right

    def inOrder(self, root):
        if not root:
            return None
        self.inOrder(root.left)
        root.left = None
        self.prev.right = root
        self.prev = root
        self.inOrder(root.right)


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass
