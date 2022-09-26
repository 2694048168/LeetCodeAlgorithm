/**
 * @file middle_node.cpp
 * @author Wei Li (weili_yzzcq@163.com)
 * @brief 链表的中间结点
 * @link: https://leetcode.cn/problems/middle-of-the-linked-list/
 * @version 0.1
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
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
    ListNode* middleNode(ListNode* head) 
    {
        // 快慢指针思想
        ListNode * ptr_slow = head;
        ListNode * ptr_fast = head;
        while (ptr_fast != nullptr && ptr_fast->next != nullptr)
        {
            ptr_slow = ptr_slow->next;
            ptr_fast = ptr_fast->next->next;
        }

        return ptr_slow; /* 当fast到达链表尾部，刚好slow到达链表中间 */
    }
};


// -----------------------------
int main(int argc, char **argv)
{
    // 1, 2, 3, 4, 5
    ListNode* head = new(ListNode);
    ListNode* second = new(ListNode);
    ListNode* third = new(ListNode);
    ListNode* forth = new(ListNode);
    ListNode* fivth = new(ListNode);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fivth;
    fivth->next = nullptr;

    head->val = 1;
    second->val =2;
    third->val = 3;
    forth->val = 4;
    fivth->val = 5;

    Solution solution;
    auto middle_node = solution.middleNode(head);
    std::cout << "The solution of this problem is " << middle_node->val << std::endl;

    return 0;
}
