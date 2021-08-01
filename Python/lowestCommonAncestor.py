#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lowestCommonAncestor.py
@Function: 二叉搜索树的最近公共祖先
@Link: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        ancestor = root
        while True:
            if p.val < ancestor.val and q.val < ancestor.val:
                ancestor = ancestor.left
            elif p.val > ancestor.val and q.val > ancestor.val:
                ancestor = ancestor.right
            else:
                break
        return ancestor


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
