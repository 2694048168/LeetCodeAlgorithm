/**
 * @File    : findShortestSubArray.cpp
 * @Brief   : 数组的度  
 * @Link    : https://leetcode-cn.com/problems/degree-of-an-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findShortestSubArray(std::vector<int> &nums)
    {
        std::unordered_map<int, std::vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else
            {
                mp[nums[i]] = {1, i, i};
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto &[_, vec] : mp)  // C++17
        {
            if (maxNum < vec[0])
            {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if (maxNum == vec[0])
            {
                if (minLen > vec[2] - vec[1] + 1)
                {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 2, 3, 1};

    Solution solution;
    auto subarray = solution.findShortestSubArray(nums);
    std::cout << "The solution of this problem is " << subarray << std::endl;

    return 0;
}
