/**
 * @File    : removeElement.cpp
 * @Brief   : 移除元素 
 * @Link    : https://leetcode-cn.com/problems/remove-element/ 
 * @Author  : Wei Li
 * @Date    : 2021-08-06
*/

#include <iostream>
#include <vector>

// 注意这些实现方法改变了元素的相对位置
class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            if (nums[left] == val)
            {
                nums[left] = nums[right - 1];
                --right;
            }
            else
            {
                ++left;
            }
        }
        return left;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{3, 2, 2, 3};
    int val = 3;

    Solution solution;
    int num_vec = solution.removeElement(nums, val);
    std::cout << "The solution of this problem is: " << num_vec << std::endl;

    return 0;
}
