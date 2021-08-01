#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: convertBST.py
@Function: 把二叉搜索树转换为累加树
@Link: https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
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
    def convertBST(self, root: TreeNode) -> TreeNode:
        def getSuccessor(node: TreeNode) -> TreeNode:
            succ = node.right
            while succ.left and succ.left != node:
                succ = succ.left
            return succ
        
        total = 0
        node = root

        while node:
            if not node.right:
                total += node.val
                node.val = total
                node = node.left
            else:
                succ = getSuccessor(node)
                if not succ.left:
                    succ.left = node
                    node = node.right
                else:
                    succ.left = None
                    total += node.val
                    node.val = total
                    node = node.left

        return root


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
