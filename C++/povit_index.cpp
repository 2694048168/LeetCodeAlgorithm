/**
 * @File    : povit_index.cpp
 * @Brief   : 寻找数组的中心下标
 * @Link    : https://leetcode.cn/problems/find-pivot-index/
 * @Author  : Wei Li (weili_yzzcq@163.com)
 * @Date    : 2022-09-23
*/

#include <iostream>
#include <vector>
#include <numeric>


class Solution 
{
public:
    int pivotIndex(std::vector<int>& nums)
    {
        auto product_sum_total = std::accumulate(nums.begin(), nums.end(), 0);
        int product_sum_left = 0;
        for (int idx = 0; idx < nums.size(); ++idx)
        {
            // product_sum_right = product_sum_total - product_sum_left - nums[idx]
            if (product_sum_total - 2 * product_sum_left == nums[idx])
            {
                return idx;
            }
            product_sum_left += nums[idx];
        }
        return -1;
    }
};


// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums_0 = {1, 7, 3, 6, 5, 6};
    std::vector<int> nums_1 = {1, 2, 3};
    std::vector<int> nums_2 = {2, 1, -1};

    Solution solution;
    int povit_index_0 = solution.pivotIndex(nums_0); /* True==3 */
    int povit_index_1 = solution.pivotIndex(nums_1); /* True==-1 */
    int povit_index_2 = solution.pivotIndex(nums_2); /* True==0 */
    std::cout << "The solution of this problem is " << povit_index_0 << std::endl;
    std::cout << "The solution of this problem is " << povit_index_1 << std::endl;
    std::cout << "The solution of this problem is " << povit_index_2 << std::endl;

    return 0;
}
