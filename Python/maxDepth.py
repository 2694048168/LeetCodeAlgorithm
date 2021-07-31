#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: maxDepth.py
@Function: 二叉树的最大深度 
@Link: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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
    def maxDepth(self, root):
        if root is None: 
            return 0 
        else: 
            left_height = self.maxDepth(root.left) 
            right_height = self.maxDepth(root.right) 
            return max(left_height, right_height) + 1

# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass