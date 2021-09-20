#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: lowestCommonAncestor3.py
@Function: 二叉搜索树的最近公共祖先
@Link: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-20
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


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


# -------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
