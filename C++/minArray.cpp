/**
 * @File    : minArray.cpp
 * @Brief   : 旋转数组的最小数字
 * @Link    : https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-06
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int minArray(std::vector<int> &numbers)
    {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high)
        {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high])
            {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high])
            {
                low = pivot + 1;
            }
            else
            {
                high -= 1;
            }
        }
        return numbers[low];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{3, 4, 5, 1, 2};
    std::vector<int> nums{3, 4, 0, 1, 2};

    Solution solution;
    auto min_number_array = solution.minArray(nums);
    std::cout << "The solution of this problem is " << min_number_array << std::endl;

    return 0;
}
