#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: postorderTraversal.py
@Function: 二叉树的后序遍历
@Link : https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-02
"""


from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return list()

        res = list()
        stack = list()
        prev = None

        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if not root.right or root.right == prev:
                res.append(root.val)
                prev = root
                root = None
            else:
                stack.append(root)
                root = root.right

        return res


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass
