/**
 * @File    : mergeTwoLists.cpp
 * @Brief   : 合并两个有序链表
 * @Link    : https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * @Author  : Wei Li
 * @Date    : 2021-07-30
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归方式
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l2)
        {
            return l1;
        }
        if (!l1)
        {
            return l2;
        }
        if (l1->val > l2->val)
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};

// 非递归方式
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0), *node = dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
