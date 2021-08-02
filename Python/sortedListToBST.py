#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: inorderTraversal.py
@Function: 二叉树的中序遍历
@Link : https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-08-02
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        def getMedian(left: ListNode, right: ListNode) -> ListNode:
            fast = slow = left
            while fast != right and fast.next != right:
                fast = fast.next.next
                slow = slow.next
            return slow

        def buildTree(left: ListNode, right: ListNode) -> TreeNode:
            if left == right:
                return None
            mid = getMedian(left, right)
            root = TreeNode(mid.val)
            root.left = buildTree(left, mid)
            root.right = buildTree(mid.next, right)
            return root

        return buildTree(head, None)


# ------------------------------
if __name__ == "__main__":
    #  test on LeetCode online.
    pass
