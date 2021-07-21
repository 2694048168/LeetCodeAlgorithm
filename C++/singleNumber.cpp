/**
 * @File    : singleNumber.cpp
 * @Brief   : 只出现一次的数字
 * @Link    : https://leetcode-cn.com/problems/single-number/
 * @Author  : Wei Li
 * @Date    : 2021-07-21
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int ans = 0;
        for (const int &num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};


// -------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{2, 2, 1};
    std::vector<int> nums{4, 1, 2, 1, 2};

    Solution solution;
    auto single_number = solution.singleNumber(nums);
    std::cout << "The solution of this problem is " << single_number << std::endl;

    return 0;
}
