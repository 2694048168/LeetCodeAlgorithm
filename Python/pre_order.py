#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: pre_order.py
@Funciton Description: N 叉树的前序遍历
@LeetCode Link: https://leetcode.cn/problems/n-ary-tree-preorder-traversal/
@Python Version: 3.10.4
@Platform: PyTorch 1.12.1+cu113
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/09/28 17:50:41
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def preorder(self, root):
        answer = []
        def dfs(node: 'Node'):
            if node is None:
                return
            answer.append(node.val)
            for ch in node.children:
                dfs(ch)
        dfs(root)

        return answer


# ----------------------------
if  __name__ == "__main__":
    pass
