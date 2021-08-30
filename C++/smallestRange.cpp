/**
 * @File    : smallestRange.cpp
 * @Brief   : 最小区间
 * @Link    : https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/
 * @Author  : Wei Li
 * @Date    : 2021-08-30
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>> &nums)
    {
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
        std::vector<int> next(size);

        auto cmp = [&](const int &u, const int &v)
        {
            return nums[u][next[u]] > nums[v][next[v]];
        };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i)
        {
            pq.emplace(i);
            maxValue = std::max(maxValue, nums[i][0]);
        }

        while (true)
        {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft)
            {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }
            if (next[row] == nums[row].size() - 1)
            {
                break;
            }
            ++next[row];
            maxValue = std::max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }

        return {rangeLeft, rangeRight};
    }
};

template <typename T>
void DispalyElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> nums{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};

    Solution solution;
    auto smallest_range = solution.smallestRange(nums);
    DispalyElement(smallest_range);

    return 0;
}
