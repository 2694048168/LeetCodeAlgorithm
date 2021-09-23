/**
 * @File    : singleNumberTwo.cpp
 * @Brief   : 数组中数字出现的次数 II
 * @Link    : https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-23
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int res = 0, temp = 0;
        for (auto each : nums)
        {
            res ^= each & ~temp;
            temp ^= each & ~res;
        }
        return res;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{9, 1, 7, 9, 7, 9, 7};

    Solution solution;
    auto single_number = solution.singleNumber(nums);
    std::cout << "The solution of this problem is " << single_number << std::endl;

    return 0;
}
