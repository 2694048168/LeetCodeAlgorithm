/**
 * @File    : productExceptSelf.cpp
 * @Brief   : 除自身以外数组的乘积
 * @Link    : https://leetcode-cn.com/problems/product-of-array-except-self/
 * @Author  : Wei Li
 * @Date    : 2021-07-20
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int length = nums.size();
        std::vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++)
        {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};


void DisplayElement(const std::vector<int> &container)
{
    std::cout << "[";
    for (auto element : container)
    {
        std::cout << element << ",";
    }
    std::cout << "]" << std::endl;
}

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3, 4};

    Solution solution;
    auto product_self = solution.productExceptSelf(nums);
    std::cout << "The original array is that : " << std::endl;
    DisplayElement(nums);
    std::cout << "The product except self array is that : " << std::endl;
    DisplayElement(product_self);

    return 0;
}
