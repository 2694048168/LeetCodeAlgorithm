#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: recoverTree.py
@Function: 恢复二叉搜索树
@Link: https://leetcode-cn.com/problems/recover-binary-search-tree/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-01
"""


class Solution(object):
    def recoverTree(self, root):
        x = None
        y = None
        pre = None
        tmp = None
        while root:
            if root.left:
                tmp = root.left
                while tmp.right and tmp.right != root:
                    tmp = tmp.right
                if tmp.right is None:
                    tmp.right = root
                    root = root.left
                else:
                    if pre and pre.val > root.val:
                        y = root
                        if not x:
                            x = pre
                    pre = root
                    tmp.right = None
                    root = root.right
            else:
                if pre and pre.val > root.val:
                    y = root
                    if not x:
                        x = pre
                pre = root
                root = root.right
        if x and y:
            x.val, y.val = y.val, x.val


# ----------------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
