/**
 * @File    : canCompleteCircuit.cpp
 * @Brief   : 加油站
 * @Link    : https://leetcode-cn.com/problems/gas-station/
 * @Author  : Wei Li
 * @Date    : 2021-08-24
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        int n = gas.size();
        int i = 0;
        while (i < n)
        {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n)
            {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas)
                {
                    break;
                }
                cnt++;
            }
            if (cnt == n)
            {
                return i;
            }
            else
            {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> gas{1, 2, 3, 4, 5};
    std::vector<int> cost{3, 4, 5, 1, 2};

    Solution solution;
    auto can_complete_circle = solution.canCompleteCircuit(gas, cost);
    std::cout << "The solution of this problem is " << can_complete_circle << std::endl;

    return 0;
}
