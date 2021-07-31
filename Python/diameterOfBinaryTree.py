#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: diameterOfBinaryTree.py
@Function: 二叉树的直径 
@Link: https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 1

        def depth(node):
            # 访问到空节点了，返回0
            if not node:
                return 0
            # 左儿子为根的子树的深度
            L = depth(node.left)
            # 右儿子为根的子树的深度
            R = depth(node.right)
            # 计算d_node即L+R+1 并更新ans
            self.ans = max(self.ans, L + R + 1)
            # 返回该节点为根的子树的深度
            return max(L, R) + 1

        depth(root)
        return self.ans - 1


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
