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
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue, res = [root], 0
        while queue:
            tmp = []
            for node in queue:
                if node.left:
                    tmp.append(node.left)
                if node.right:
                    tmp.append(node.right)
            queue = tmp
            res += 1
        return res


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
