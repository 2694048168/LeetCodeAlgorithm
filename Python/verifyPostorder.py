#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: verifyPostorder.py
@Function: 二叉搜索树的后序遍历序列
@Link : https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-21
"""


from typing import List


class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if len(postorder) < 2:
            return True
        rightindex = 0
        root = postorder[-1]
        n = len(postorder)
        while rightindex < n - 1:
            if postorder[rightindex] < root:
                rightindex += 1
            else:
                break
        for i in range(rightindex, n - 1):
            if postorder[i] < root:
                return False
        return self.verifyPostorder(postorder[:rightindex]) and self.verifyPostorder(postorder[rightindex: n - 1])


# ------------------------------
if __name__ == "__main__":
    # test on leetcode online.
    pass
