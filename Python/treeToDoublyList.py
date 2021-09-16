#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: treeToDoublyList.py
@Function: 二叉搜索树与双向链表
@Link: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-09-16
"""


# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def dfs(cur):
            if not cur:
                return
            dfs(cur.left)  # 递归左子树
            if self.pre:  # 修改节点引用
                self.pre.right, cur.left = cur, self.pre
            else:  # 记录头节点
                self.head = cur
            self.pre = cur  # 保存 cur
            dfs(cur.right)  # 递归右子树

        if not root:
            return
        self.pre = None
        dfs(root)
        self.head.left, self.pre.right = self.pre, self.head
        return self.head


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
