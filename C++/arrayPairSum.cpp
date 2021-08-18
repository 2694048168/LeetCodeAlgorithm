/**
 * @File    : arrayPairSum.cpp
 * @Brief   : 数组拆分 I
 * @Link    : https://leetcode-cn.com/problems/array-partition-i/
 * @Author  : Wei Li
 * @Date    : 2021-08-18
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int arrayPairSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            ans += nums[i];
        }
        return ans;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{1,4,3,2};
    std::vector<int> nums{6, 2, 6, 5, 1, 2};

    Solution solution;
    auto pair_max_sum = solution.arrayPairSum(nums);
    std::cout << "The solution of this problem is " << pair_max_sum << std::endl;

    return 0;
}
