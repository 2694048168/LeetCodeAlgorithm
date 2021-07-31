#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: isSymmetric.py
@Function: 对称二叉树
@Link: https://leetcode-cn.com/problems/symmetric-tree/
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

# 递归
# 先序遍历（父亲 左孩子 右孩子）和与其对称的先序遍历（父亲 右孩子 左孩子），比对结果是否相同
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def search(left, right):
            if left is None and right is None:
                return True
            if left is None or right is None:
                return False
            return left.val == right.val and search(left.left, right.right) and search(left.right, right.left)
        return search(root, root)


# 迭代
# 层次遍历，比对每一层结果是否对称，
# 注意空结点一定要用 null 补充，方便比对，下一层就不需要在 null 结点继续拓展了
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return False
        queue = [root, root]
        while queue:
            left = queue.pop()
            right = queue.pop()
            if left is None and right is None:
                continue
            if left is None or right is None or left.val != right.val:
                return False
            queue.append(left.left)
            queue.append(right.right)
            queue.append(left.right)
            queue.append(right.left)

        return True


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
