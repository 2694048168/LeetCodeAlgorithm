/**
 * @File    : dailyTemperatures.cpp
 * @Brief   : 每日温度
 * @Link    : https://leetcode-cn.com/problems/daily-temperatures/
 * @Author  : Wei Li
 * @Date    : 2021-07-25
*/

#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        int n = temperatures.size();
        std::vector<int> ans(n);
        std::stack<int> indices;
        for (int i = 0; i < n; ++i)
        {
            while (!indices.empty())
            {
                int pre_index = indices.top();
                if (temperatures[i] <= temperatures[pre_index])
                {
                    break;
                }
                indices.pop();
                ans[pre_index] = i - pre_index;
            }
            indices.push(i);
        }
        return ans;
    }
};

template <typename T>
void DisplayElement(const T& container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};

    Solution solution;
    auto daily_temperature = solution.dailyTemperatures(temperatures);
    DisplayElement(daily_temperature);

    return 0;
}
