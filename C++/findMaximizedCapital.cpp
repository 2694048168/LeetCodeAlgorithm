/**
 * @File    : findMaximizedCapital.cpp
 * @Brief   : IPO
 * @Link    : https://leetcode-cn.com/problems/ipo/
 * @Author  : Wei Li
 * @Date    : 2021-08-25
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

class Solution
{
public:
    int findMaximizedCapital(int k, int w, std::vector<int> &profits, std::vector<int> &capital)
    {
        std::vector<std::pair<int, int>> capital2profits;
        for (int i = 0; i < profits.size(); i++)
        {
            capital2profits.push_back({capital[i], profits[i]});
        }
        auto cmp = [&](std::pair<int, int> &a, std::pair<int, int> &b)
        {
            return a.first < b.first;
        };
        std::sort(capital2profits.begin(), capital2profits.end(), cmp);
        int haveMoney = w;
        std::priority_queue<int> maxProfit;
        int i = 0;
        while (k--)
        {
            for (; i < capital2profits.size(); i++)
            {
                if (capital2profits[i].first <= haveMoney)
                {
                    maxProfit.push(capital2profits[i].second);
                }
                else
                    break;
            }
            if (maxProfit.empty())
                break;
            haveMoney += maxProfit.top();
            maxProfit.pop();
        }
        return haveMoney;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    int k = 2, w = 0;
    std::vector<int> profits{1, 2, 3};
    std::vector<int> captial{0, 1, 1};

    Solution solution;
    auto find_max_min_capial = solution.findMaximizedCapital(k, w, profits, captial);
    std::cout << "The soluton of this problem is " << find_max_min_capial << std::endl;

    return 0;
}
