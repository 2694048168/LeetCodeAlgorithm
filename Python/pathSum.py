#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: pathSum.py
@Function: 路径总和 III 
@Link: https://leetcode-cn.com/problems/path-sum-iii/
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


# 精简版，五行代码不解释
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def dfs(root, sumlist):
            if root is None:
                return 0
            sumlist = [num + root.val for num in sumlist] + [root.val]
            return sumlist.count(sum) + dfs(root.left, sumlist) + dfs(root.right, sumlist)
        return dfs(root, [])


# 展开版，易理解
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:

        def dfs(root, sumlist):
            if root is None:
                return 0

            sumlist = [num+root.val for num in sumlist]
            sumlist.append(root.val)

            count = 0
            for num in sumlist:
                if num == sum:
                    count += 1
            # count = sumlist.count(sum)

            return count + dfs(root.left, sumlist) + dfs(root.right, sumlist)

        return dfs(root, [])


# ---------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
