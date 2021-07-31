#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: delNodes.py
@Function: 删点成林
@Link: https://leetcode-cn.com/problems/delete-nodes-and-return-forest/
@Python Version: 3.8
@Author: Wei Li
@Date: 2021-07-31
"""

from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        self.res = []
        #---- 集合，加快查找
        del_set = set()
        for x in to_delete:
            del_set.add(x)

        #---------------- 后序遍历 从下往上的删
        def dfs_LRN(root: TreeNode) -> TreeNode:
            if root == None:
                return root
            root.left = dfs_LRN(root.left)
            root.right = dfs_LRN(root.right)
            #----- 如果root被删了，左子和右子就单独成树了
            if root.val in del_set:
                if root.left:
                    self.res.append(root.left)
                if root.right:
                    self.res.append(root.right)
                root = None
            return root

        rt = dfs_LRN(root)
        if rt:
            self.res.append(rt)
        return self.res


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
