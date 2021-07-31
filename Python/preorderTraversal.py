#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: preorderTraversal.py
@Function: 二叉树的前序遍历
@Link: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-31
"""


from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = list()
        if not root:
            return res

        stack = []
        node = root
        while stack or node:
            while node:
                res.append(node.val)
                stack.append(node)
                node = node.left
            node = stack.pop()
            node = node.right
        return res


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
