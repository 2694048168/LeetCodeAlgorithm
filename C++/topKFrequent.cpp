/**
 * @File    : topKFrequent.cpp
 * @Brief   : 前 K 个高频元素 桶排序
 * @Link    : https://leetcode-cn.com/problems/top-k-frequent-elements/
 * @Author  : Wei Li
 * @Date    : 2021-07-10
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> counts;
        int max_count = 0;
        for (const int &num : nums)
        {
            max_count = std::max(max_count, ++counts[num]);
        }

        std::vector<std::vector<int>> buckets(max_count + 1);
        for (const auto &p : counts)
        {
            buckets[p.second].push_back(p.first);
        }

        std::vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; --i)
        {
            for (const int &num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                {
                    break;
                }
            }
        }

        return ans;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        std::cout << *element << " ";
    }
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // auto solution = Solution();
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    auto topk_value = solution->topKFrequent(nums, k);
    // auto topk_value = solution.topKFrequent(nums, k);
    DisplayElement(topk_value);

    return 0;
}
