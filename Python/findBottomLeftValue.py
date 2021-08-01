#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findBottomLeftValue.py
@Function: 找树左下角的值
@Link: https://leetcode-cn.com/problems/find-bottom-left-tree-value/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-01
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        depth = 0
        self.res = []

        def level(root, depth):
            if not root:
                return
            if depth == len(self.res):
                self.res.append([])
                self.res[depth].append(root.val)
            level(root.left, depth+1)
            level(root.right, depth+1)
        level(root, depth)
        return self.res[-1][0]


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
