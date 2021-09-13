/**
 * @File    : mergeTwoLists2.cpp
 * @Brief   : 合并两个排序的链表
 * @Link    : https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-13
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2)
            return l1 ? l1 : l2;
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
