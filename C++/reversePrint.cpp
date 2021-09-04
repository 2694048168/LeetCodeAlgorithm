/**
 * @File    : reversePrint.cpp
 * @Brief   : 从尾到头打印链表
 * @Link    :  https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-04
*/

#include <iostream>
#include <vector>
#include <stack>

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
    std::vector<int> reversePrint(ListNode *head)
    {
        std::stack<int> s;
        std::vector<int> res;
        ListNode *pre = head;
        while (pre)
        {
            s.push(pre->val);
            pre = pre->next;
        }
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
