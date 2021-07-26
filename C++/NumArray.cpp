/**
 * @File    : NumArray.cpp
 * @Brief   : 区域和检索 - 数组不可变
 * @Link    : https://leetcode-cn.com/problems/range-sum-query-immutable/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <vector>
#include <numeric>

class NumArray
{
    std::vector<int> psum;

public:
    NumArray(std::vector<int> nums) : psum(nums.size() + 1, 0)
    {
        std::partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
    }
    int sumRange(int i, int j)
    {
        return psum[j + 1] - psum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
