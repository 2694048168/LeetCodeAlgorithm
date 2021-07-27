/**
 * @File    : findDuplicate.cpp
 * @Brief   : 寻找重复数
 * @Link    : https://leetcode-cn.com/problems/find-the-duplicate-number/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 3, 4, 2, 2};

    Solution solution;
    auto find_duplicate = solution.findDuplicate(nums);
    std::cout << "The solution of this problem is " << find_duplicate << std::endl;

    return 0;
}
