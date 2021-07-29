/**
 * @File    : reverseList.cpp
 * @Brief   : 反转链表
 * @Link    : https://leetcode-cn.com/problems/reverse-linked-list/
 * @Author  : Wei Li
 * @Date    : 2021-07-29
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

// 迭代方式
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *next;
        // 修改指针的指向即可
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// 递归方式
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
