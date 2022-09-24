/**
 * @File: max_sub_array.cpp
 * @Brief: 最大子数组和
 * @Link: https://leetcode.cn/problems/maximum-subarray/
 * @Author: Wei Li (weili_yzzcq@163.com)
 * @Date: 2022-09-24
*/

#include <iostream>
#include <vector>


class Solution 
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        // f(i - 1) and f(i) accumula_sum
        int pre_sum=0, max_sum = nums[0];
        for (const auto &num : nums) /* T(n) = big-O(nums.size()) */
        {
            // update f(i-1) 贪心，选择最大的
            pre_sum = std::max(pre_sum + num, num);
            max_sum = std::max(pre_sum, max_sum);
        }

        return max_sum;
    }
};


// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> int_vec1 {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> int_vec2 {5,4,-1,7,8};
    std::vector<int> int_vec3 {1};

    Solution solution;
    auto max_sum1 = solution.maxSubArray(int_vec1);
    auto max_sum2 = solution.maxSubArray(int_vec2);
    auto max_sum3 = solution.maxSubArray(int_vec3);
    std::cout << "The solution of this problem is " << max_sum1 << std::endl;
    std::cout << "The solution of this problem is " << max_sum2 << std::endl;
    std::cout << "The solution of this problem is " << max_sum3 << std::endl;

    return 0;
}
