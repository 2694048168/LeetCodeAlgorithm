/**
 * @File    : singleNonDuplicate.cpp
 * @Brief   : 有序数组中的单一元素
 * @Link    : https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-09
*/

#include <iostream>
#include <vector>


class Solution
{
public:
    int singleNonDuplicate(std::vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            bool halvesAreEven = (high - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid])
            {
                if (halvesAreEven)
                {
                    low = mid + 2;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else if (nums[mid - 1] == nums[mid])
            {
                if (halvesAreEven)
                {
                    high = mid - 2;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[low];
    }
};


// 仅对偶数索引进行二分搜索
class Solution
{
public:
    int singleNonDuplicate(std::vector<int>& nums)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1)
                mid--;
            if (nums[mid] == nums[mid + 1])
            {
                lo = mid + 2;
            }
            else
            {
                hi = mid;
            }
        }
        return nums[lo];
    }
};


// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums = {1,1,2,3,3,4,4,8,8};
    // std::vector<int> nums = {3,3,7,7,10,11,11};

    auto solution = Solution();
    int odd_value = solution.singleNonDuplicate(nums);
    std::cout << "The solution of this problem is : " << odd_value << std::endl;

    return 0;
}
