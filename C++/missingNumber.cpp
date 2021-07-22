/**
 * @File    : missingNumber.cpp
 * @Brief   : 丢失的数字
 * @Link    : https://leetcode-cn.com/problems/missing-number/
 * @Author  : Wei Li
 * @Date    : 2021-07-22
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        int n = nums.size();
        int check = 0;
        for (int val : nums)
        {
            check ^= val;
        }
        for (int i = 0; i <= n; ++i)
        {
            check ^= i;
        }
        return check;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{3, 0, 1};

    Solution solution;
    auto missing_number = solution.missingNumber(nums);
    std::cout << "The solution of this problem is " << missing_number << std::endl;

    return 0;
}
