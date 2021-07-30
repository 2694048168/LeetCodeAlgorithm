/**
 * @File    : removeNthFromEnd.cpp
 * @Brief   : 删除链表的倒数第 N 个结点
 * @Link    : https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
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

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = dummy;
        for (int i = 0; i < n; ++i)
        {
            first = first->next;
        }
        while (first)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

// -----------------------------
int main(int argc, char **argv)
{

    return 0;
}
