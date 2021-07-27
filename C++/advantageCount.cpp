/**
 * @File    : advantageCount.cpp
 * @Brief   : 优势洗牌
 * @Link    : https://leetcode-cn.com/problems/advantage-shuffle/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class Solution
{
public:
    std::vector<int> advantageCount(std::vector<int> &A, std::vector<int> &B)
    {
        int size = A.size();
        if (size == 0 || size != B.size())
        {
            return std::vector<int>();
        }
        std::vector<std::pair<int, int>> bIndex(size);
        std::vector<int> result(size);
        for (int i = 0; i < size; i++)
        {
            bIndex[i] = {B[i], i};
        }
        std::sort(A.begin(), A.end());
        std::sort(bIndex.begin(), bIndex.end());
        auto it = bIndex.begin();
        auto rIt = bIndex.rbegin();
        for (int i = 0; i < size; i++)
        {
            if (A[i] > it->first)
            {
                result[it->second] = A[i];
                it++;
            }
            else
            {
                result[rIt->second] = A[i];
                rIt++;
            }
        }
        return result;
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

// --------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums1{12, 24, 8, 32}, nums2{1, 10, 4, 11};

    Solution solution;
    auto advantage_count = solution.advantageCount(nums1, nums2);
    DisplayElement(advantage_count);

    return 0;
}
