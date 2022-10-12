/**
 * @file num_components.cpp
 * @author Wei Li (weili_yzzcq@163.com)
 * @brief 链表组件
 * @cite https://leetcode.cn/problems/linked-list-components/
 * @version 0.1
 * @date 2022-10-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @brief 给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值
 * 同时给定列表 nums，该列表是上述链表中整型值的一个子集。
 * 返回列表 nums 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 nums 中）构成的集合。
 *
 * solution: 计算组件的起始位置
 * 需要计算组件的个数，只需在链表中计算有多少组件的起始位置即可。
 * 当一个节点满足以下条件之一时，它是组件的起始位置：
 * 1. 节点的值在数组 nums 中且节点位于链表起始位置；
 * 2. 节点的值在数组 nums 中且节点的前一个点不在数组 nums 中。
 * 3. 遍历链表，计算出满足条件的点的个数即可。
 *
 * 因为需要多次判断值是否位于数组 nums 中，
 * 用一个哈希集合保存数组 nums 中的点可以降低时间复杂度。
 *
 */
class Solution
{
public:
    int numComponents(ListNode *head, std::vector<int> &nums)
    {
        std::unordered_set<int> hash_table;
        for (auto num : nums) /* 将数组值存入哈希集合中 */
        {
            hash_table.emplace(num);
        }

        int num_components = 0;
        bool inSet = false; /* 标志前一个节点是否在数组中 */
        while (head != nullptr) /* 遍历链表 */
        {
            if (hash_table.count(head->val)) /* 判断节点的值是否在数组中 */
            {
                if (!inSet) {
                    inSet = true;
                    ++num_components;
                }
            }
            else
            {
                inSet = false;
            }
            head = head->next;
        }

        return num_components;
    }
};

// ------------------------------------
int main(int argc, char const *argv[])
{
    std::vector<int> nums{0, 1, 3};
    // head = [0,1,2,3]
    ListNode* head = new(ListNode);
    ListNode* second = new(ListNode);
    ListNode* third = new(ListNode);
    ListNode* forth = new(ListNode);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = nullptr;

    head->val = 1;
    second->val =2;
    third->val = 3;
    forth->val = 4;

    Solution solution;
    auto num_components = solution.numComponents(head, nums);
    std::cout << num_components << std::endl;

    return 0;
}
