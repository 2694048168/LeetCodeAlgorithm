#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: buildTree2.py
@Function: 从中序与后序遍历序列构造二叉树
@Link : https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(in_left, in_right):
            # 如果这里没有节点构造二叉树了，就结束
            if in_left > in_right:
                return None
            
            # 选择 post_idx 位置的元素作为当前子树根节点
            val = postorder.pop()
            root = TreeNode(val)

            # 根据 root 所在位置分成左右两棵子树
            index = idx_map[val]
 
            # 构造右子树
            root.right = helper(index + 1, in_right)
            # 构造左子树
            root.left = helper(in_left, index - 1)
            return root
        
        # 建立（元素，下标）键值对的哈希表
        idx_map = {val:idx for idx, val in enumerate(inorder)} 
        return helper(0, len(inorder) - 1)


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass
