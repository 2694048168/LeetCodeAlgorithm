/**
 * @File    : twoSum2.cpp
 * @Brief   : 两数之和 II - 输入有序数组
 * @Link    : https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * @Author  : Wei Li
 * @Date    : 2021-07-06
*/

#include <iostream>
#include <vector>
#include <memory>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        int left_index = 0, right_index = numbers.size()  - 1, sum = 0;
        while (left_index < right_index)
        {
            sum = numbers[left_index] + numbers[right_index];
            if (sum == target)
            {
                break;
            }
            if (sum < target)
            {
                ++left_index;
            }
            else
            {
                --right_index;
            }
        }
        return std::vector<int> {left_index + 1, right_index + 1};
    }
};


// 模板
template <typename T>
void DisplayContents(const T& container)
{
  for (auto element = container.cbegin(); element != container.cend(); ++element)
  {
    std::cout << *element << " ";
    // std::cout << *element << std::endl;
  }
  std::cout << std::endl << container.size() << std::endl;
}

// ------------------------------
int main(int argc, char** argv)
{
    // --------TEST Case-----------
    // std::vector<int> numbers = {2, 7, 11, 15};
    // int target = 9;

    // std::vector<int> numbers = {2, 3, 4};
    // int target = 6;

    std::vector<int> numbers = {-1, 0};
    int target = -1;
    // --------TEST Case-----------

    // auto solution = Solution();
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    auto index = solution->twoSum(numbers, target);
    // auto index = solution.twoSum(numbers, target);
    std::cout << "The solution of this problem is : " << std::end;
    DisplayContents(index);
    
    return 0;
}
