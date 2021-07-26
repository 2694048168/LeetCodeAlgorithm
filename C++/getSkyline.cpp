/**
 * @File    : getSkyline.cpp
 * @Brief   : 天际线问题
 * @Link    : https://leetcode-cn.com/problems/the-skyline-problem/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

class Solution
{
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings)
    {
        std::vector<std::vector<int>> ans;
        std::priority_queue<std::pair<int, int>> max_heap; // <高度, 右端>
        int i = 0, len = buildings.size();
        int cur_x, cur_h;
        while (i < len || !max_heap.empty())
        {
            if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second)
            {
                cur_x = buildings[i][0];
                while (i < len && cur_x == buildings[i][0])
                {
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    ++i;
                }
            }
            else
            {
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && cur_x >= max_heap.top().second)
                {
                    max_heap.pop();
                }
            }
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1])
            {
                ans.push_back({cur_x, cur_h});
            }
        }
        return ans;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        for (auto value : element)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};

    Solution solution;
    auto get_sky_line = solution.getSkyline(buildings);
    DisplayElement(get_sky_line);

    return 0;
}
