/**
 * @File    : singleNumbers.cpp
 * @Brief   : 数组中数字出现的次数
 * @Link    : https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-23
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> singleNumbers(std::vector<int> &nums)
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

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{1, 4, 6, 4};
    std::vector<int> nums{1, 2, 10, 4, 1, 4, 3, 3};

    Solution solution;
    auto single_number = solution.singleNumbers(nums);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(single_number);

    return 0;
}
