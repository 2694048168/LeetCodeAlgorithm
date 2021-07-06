/**
 * @File    : reconstructQueue.cpp
 * @Brief   : 根据身高重建队列 贪心策略
 * @Link    : https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 * @Author  : Wei Li
 * @Date    : 2021-07-06
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
    {
        std::sort(people.begin(), people.end(), [](const std::vector<int> &u, const std::vector<int> &v)
                  { return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]); });

        int num_size = people.size();
        std::vector<std::vector<int>> ans(num_size);
        for (const std::vector<int> &person : people)
        {
            int spaces = person[1] + 1;
            for (size_t i = 0; i < num_size; ++i)
            {
                if (ans[i].empty())
                {
                    --spaces;
                    if (!spaces)
                    {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

// 模板
template <typename T>
void DisplayContents(const T &container)
{
    for (const std::vector<int> &person : container)
    {
        for (auto element = person.cbegin(); element != person.cend(); ++element)
        {
            std::cout << *element << " ";
            // std::cout << *element << std::endl;
        }
    }
    std::cout << std::endl
              << container.size() << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    // std::vector<std::vector<int>> people = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};

    auto solution = Solution();
    auto reconstruct_queue = solution.reconstructQueue(people);
    DisplayContents(reconstruct_queue);

    return 0;
}