#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: getMinimumDifference.py
@Function: 二叉搜索树的最小绝对差
@Link: https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
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
    def getMinimumDifference(self, root: TreeNode) -> int:
        # 初始化，最小值赋值为无穷大，last_value记录上一个节点的值
        min_value, last_value = float("inf"), -1

        def pengding_num(val):
            nonlocal min_value, last_value
            # 第一个节点赋值给last_value
            if last_value == -1:
                last_value = val
            else:
                # 每次求差的绝对值的最小值，更新
                min_value = min(min_value, abs(val - last_value))
                last_value = val
        # 中序遍历

        def mid_order(root):
            nonlocal min_value, last_value
            if root:
                mid_order(root.left)
                # 处理当前节点
                pengding_num(root.val)
                mid_order(root.right)
        mid_order(root)
        return min_value


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
