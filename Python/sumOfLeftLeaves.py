#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: sumOfLeftLeaves.py
@Function: 左叶子之和
@Link: https://leetcode-cn.com/problems/sum-of-left-leaves/
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
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        def isLeafNode(node): return not node.left and not node.right

        def dfs(node: TreeNode) -> int:
            ans = 0
            if node.left:
                ans += node.left.val if isLeafNode(
                    node.left) else dfs(node.left)
            if node.right and not isLeafNode(node.right):
                ans += dfs(node.right)
            return ans

        return dfs(root) if root else 0


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
