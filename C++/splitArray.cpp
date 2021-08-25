/**
 * @File    : splitArray.cpp
 * @Brief   : 分割数组的最大值
 * @Link    : https://leetcode-cn.com/problems/split-array-largest-sum/
 * @Author  : Wei Li
 * @Date    : 2021-08-25
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    bool check(std::vector<int> &nums, int x, int m)
    {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] > x)
            {
                cnt++;
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }

    int splitArray(std::vector<int> &nums, int m)
    {
        long long left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            right += nums[i];
            if (left < nums[i])
            {
                left = nums[i];
            }
        }
        while (left < right)
        {
            long long mid = (left + right) >> 1;
            if (check(nums, mid, m))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    // std::vector<int> nums{7, 2, 5, 10, 8};
    int m = 2;

    Solution solution;
    auto split_array_result = solution.splitArray(nums, m);
    std::cout << "The solution of this problem is " << split_array_result << std::endl;

    return 0;
}
