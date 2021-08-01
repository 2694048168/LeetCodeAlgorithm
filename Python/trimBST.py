#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: trimBST.py
@Function: 修剪二叉搜索树
@Link: https://leetcode-cn.com/problems/trim-a-binary-search-tree/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-01
"""


class Solution(object):
    def trimBST(self, root, L, R):
        def trim(node):
            if not node:
                return None
            elif node.val > R:
                return trim(node.left)
            elif node.val < L:
                return trim(node.right)
            else:
                node.left = trim(node.left)
                node.right = trim(node.right)
                return node

        return trim(root)


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
