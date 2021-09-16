#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: pathSum2.py
@Function: 二叉树中和为某一值的路径
@Link: https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-09-16
"""

from typing import List
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        ret = list()
        parent = collections.defaultdict(lambda: None)

        def getPath(node: TreeNode):
            tmp = list()
            while node:
                tmp.append(node.val)
                node = parent[node]
            ret.append(tmp[::-1])

        if not root:
            return ret

        que_node = collections.deque([root])
        que_total = collections.deque([0])

        while que_node:
            node = que_node.popleft()
            rec = que_total.popleft() + node.val

            if not node.left and not node.right:
                if rec == target:
                    getPath(node)
            else:
                if node.left:
                    parent[node.left] = node
                    que_node.append(node.left)
                    que_total.append(rec)
                if node.right:
                    parent[node.right] = node
                    que_node.append(node.right)
                    que_total.append(rec)

        return ret


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
