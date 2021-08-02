#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findTarget2.py
@Function: 两数之和 IV - 输入 BST
@Link : https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-02
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        nums = []

        def mid_order(root):
            if root:
                mid_order(root.left)
                nums.append(root.val)
                mid_order(root.right)
        mid_order(root)
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] + nums[r] == k:
                return True
            elif nums[l] + nums[r] > k:
                r -= 1
            else:
                l += 1
        return False


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass
