/**
 * @File    : smallestDistancePair.cpp
 * @Brief   : 找出第 k 小的距离对
 * @Link    : https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/
 * @Author  : Wei Li
 * @Date    : 2021-08-27
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int smallestDistancePair(std::vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        int min = 0, max = nums.back() - nums.front();
        while (min < max)
        {
            int mid = (min + max) / 2;
            int count = 0;
            for (int l = 0, r = 0; r < nums.size(); r++)
            {
                while (l < r && nums[r] - nums[l] > mid)
                    l++;
                count += r - l;
            }
            if (count >= k)
                max = mid;
            else
                min = mid + 1;
        }
        return min;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 3, 1};
    int k = 1;

    Solution solution;
    auto smallest_distance = solution.smallestDistancePair(nums, 1);
    std::cout << "The solution of this problem is " << smallest_distance << std::endl;

    return 0;
}
