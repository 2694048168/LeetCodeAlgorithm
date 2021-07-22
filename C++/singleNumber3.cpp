/**
 * @File    : singleNumber3.cpp
 * @Brief   : 只出现一次的数字 III
 * @Link    : https://leetcode-cn.com/problems/single-number-iii/
 * @Author  : Wei Li
 * @Date    : 2021-07-22
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> singleNumber(std::vector<int> &nums)
    {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return std::vector<int>{a, b};
    }
};

void DisplayElement(const std::vector<int> & container)
{
    for (const auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 1, 3, 2, 5};

    Solution solution;
    auto single_nums = solution.singleNumber(nums);
    DisplayElement(single_nums);

    return 0;
}
