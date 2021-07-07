/**
 * @File    : detectCycle.cpp
 * @Brief   : 环形链表 II 双指针策略
 * @Link    : https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-07
*/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// https://en.wikipedia.org/wiki/Cycle_detection
// 快慢指针算法
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // 判断是否存在环路
        do
        {
            if (!fast || !fast->next)
            {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        // 如果存在，查找环路节点
        fast = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};


// --------------------------------
int main(int argc, char **argv)
{
    // test case

    return 0;
}
