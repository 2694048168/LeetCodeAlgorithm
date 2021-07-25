/**
 * @File    : mergeKLists.cpp
 * @Brief   : 合并K个升序链表
 * @Link    : https://leetcode-cn.com/problems/merge-k-sorted-lists/ 
 * @Author  : Wei Li
 * @Date    : 2021-07-25
*/

#include <iostream>
#include <vector>
#include <queue>

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
    struct Comp
    {
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        std::priority_queue<ListNode *, std::vector<ListNode *>, Comp> q;
        for (ListNode *list : lists)
        {
            if (list)
            {
                q.push(list);
            }
        }
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (!q.empty())
        {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if (cur->next)
            {
                q.push(cur->next);
            }
        }
        return dummy->next;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
