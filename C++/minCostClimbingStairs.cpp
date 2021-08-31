/**
 * @File    : minCostClimbingStairs.cpp
 * @Brief   : 使用最小花费爬楼梯
 * @Link    : https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * @Author  : Wei Li
 * @Date    : 2021-08-31
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        int n = cost.size();
        int prev = 0, curr = 0;
        for (int i = 2; i <= n; i++)
        {
            int next = std::min(curr + cost[i - 1], prev + cost[i - 2]);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> cost{10, 15, 20};

    Solution solution;
    auto min_cost_clim_stairs = solution.minCostClimbingStairs(cost);
    std::cout << "The solution of this problem is " << min_cost_clim_stairs << std::endl;

    return 0;
}
