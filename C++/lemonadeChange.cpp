/**
 * @File    : lemonadeChange.cpp
 * @Brief   : 柠檬水找零
 * @Link    : https://leetcode-cn.com/problems/lemonade-change/
 * @Author  : Wei Li
 * @Date    : 2021-08-18
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    bool lemonadeChange(std::vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (auto &bill : bills)
        {
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                {
                    return false;
                }
                five--;
                ten++;
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> bills{5, 5, 5, 10, 20};
    std::vector<int> bills{5, 5, 10, 10, 20};

    Solution solution;
    auto check_change = solution.lemonadeChange(bills);
    std::cout << "The solution of this problem is " << std::boolalpha << check_change << std::endl;

    return 0;
}
