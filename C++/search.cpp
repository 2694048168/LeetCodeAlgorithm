/**
 * @File    : search.cpp
 * @Brief   : 搜索旋转排序数组 II
 * @Link    : https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-08
*/

#include <iostream>
#include <vector>
#include <memory>

/**
 * 即使数组被旋转过，仍然可以利用这个数组的递增性，使用二分查找。
 * 对于当前的中点，如果它指向的值小于等于右端，那么说明右区间是排好序的；
 * 反之，那么说明左区间是排好序的。
 * 
 * 如果目标值位于排好序的区间内，可以对这个区间继续二分查找；
 * 反之，我们对于另一半区间继续二分查找。
 * 
 * 注意，因为数组存在重复数字，如果中点和左端的数字相同，并不能确定是左区间全部相同，还是右区间完全相同
 * 在这种情况下，我们可以简单地将左端点右移一位，然后继续进行二分查找 
 */
class Solution
{
public:
    bool search(std::vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[start] == nums[end])
            {
                // 无法判断哪个区间是增序的 
                ++start;
            }
            else if (nums[mid] <= nums[end])
            {
                // 右区间是增序的
                if (target > nums[mid] && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            {
                // 左区间是增序的
                if (target >= nums[start] && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return false;
    }
};


// ------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    // int target = 0;
    // int target = 8;

    std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 3;

    // auto solution = Solution();
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    bool check = solution->search(nums, target);
    // bool check = solution.search(nums, target);
    std::cout << "The solution of this problem is : " << std::boolalpha << check << std::endl;

    return 0;
}