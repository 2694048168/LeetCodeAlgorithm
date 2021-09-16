#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: kthLargest.py
@Function: 二叉搜索树的第k大节点
@Link: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-09-16
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        def dfs(root):
            if not root:
                return
            dfs(root.right)
            if self.k == 0:
                return
            self.k -= 1
            if self.k == 0:
                self.res = root.val
            dfs(root.left)

        self.k = k
        dfs(root)
        return self.res


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
