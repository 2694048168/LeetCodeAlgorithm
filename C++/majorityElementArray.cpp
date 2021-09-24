/**
 * @File    : majorityElementArray.cpp
 * @Brief   : 数组中出现次数超过一半的数字  
 * @Link    : https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-24
*/

#include <iostream>
#include <vector>

class Solution2
{
    int count_in_range(std::vector<int> &nums, int target, int lo, int hi)
    {
        int count = 0;
        for (int i = lo; i <= hi; ++i)
            if (nums[i] == target)
                ++count;
        return count;
    }
    int majority_element_rec(std::vector<int> &nums, int lo, int hi)
    {
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) / 2;
        int left_majority = majority_element_rec(nums, lo, mid);
        int right_majority = majority_element_rec(nums, mid + 1, hi);
        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2)
            return left_majority;
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2)
            return right_majority;
        return -1;
    }

public:
    int majorityElement(std::vector<int> &nums)
    {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
};

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int ans = 0;
        int votes = 0;
        for (int num : nums)
        {
            if (votes == 0)
                ans = num;
            votes += num == ans ? 1 : -1;
        }
        return ans;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};

    Solution solution;
    auto major_number = solution.majorityElement(nums);
    std::cout << "The solution of this problem is " << major_number << std::endl;

    return 0;
}
