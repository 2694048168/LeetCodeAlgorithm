/**
 * @File: inter_set.cpp
 * @Brief: 两个数组的交集
 * @Link: https://leetcode.cn/problems/intersection-of-two-arrays/
 * @Author: Wei Li (weili_yzzcq@163.com)
 * @Date: 2022-09-24
*/

#include <iostream>
#include <vector>
#include <unordered_set>


class Solution 
{
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::unordered_set<int> set1, set2; /* hash-table set to nums1 and nums2 */
        for (auto &num : nums1)
        {
            set1.insert(num);
        }
        for (auto &num : nums2)
        {
            set2.insert(num);
        }

        return get_intersection(set1, set2);
    }

    std::vector<int> get_intersection(std::unordered_set<int>& set1, std::unordered_set<int>& set2)
    {
        // 遍历哈希表中元素最小的集合
        if (set1.size() > set2.size())
        {
            get_intersection(set2, set1);
        }

        std::vector<int> inter_set;
        for (auto &num : set1)
        {
            if (set2.count(num))
            {
                inter_set.push_back(num);
            }
        }

        return inter_set;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> int_vec1 {4, 9, 5};
    std::vector<int> int_vec2 {9, 4, 9, 8, 4};
    // std::vector<int> int_vec1 {1, 2, 2, 1};
    // std::vector<int> int_vec2 {2, 2};

    Solution solution;
    auto inter_set = solution.intersection(int_vec1, int_vec2);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(inter_set);

    return 0;
}
