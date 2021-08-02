#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: constructFromPrePost.py
@Function: 根据前序和后序遍历构造二叉树
@Link : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    def constructFromPrePost(self, pre, post):
        def make(i0, i1, N):
            if N == 0:
                return None
            root = TreeNode(pre[i0])
            if N == 1:
                return root

            for L in range(N):
                if post[i1 + L - 1] == pre[i0 + 1]:
                    break

            root.left = make(i0 + 1, i1, L)
            root.right = make(i0 + L + 1, i1 + L, N - 1 - L)
            return root

        return make(0, 0, len(pre))


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass