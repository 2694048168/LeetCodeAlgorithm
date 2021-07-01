/**
 * @file    : expect_number.cpp
 * @brief   : 期望个数的统计, 分析的结果就是计算一个数组的不同元素的个数
 * @link    ：https://leetcode-cn.com/problems/qi-wang-ge-shu-tong-ji/
 * @author  : Wei Li
 * @date    : 2021-06-29
*/


#include <iostream>
#include <vector>
#include <algorithm>


class Solution
{
public:
    int expectNumber(std::vector<int>& scores) 
    {
        // https://en.cppreference.com/w/cpp/algorithm/sort
        std::sort(scores.begin(), scores.end());
        
        // https://en.cppreference.com/w/cpp/algorithm/unique
        return std::unique(scores.begin(), scores.end()) - scores.begin();
    }
};

// 换一种写法，算法的本质思想不变
class Solution {
public:
    int expectNumber(std::vector<int>& scores) 
    {
        std::sort(scores.begin(),scores.end());
        int ret = 0;
        for (int i=0; i<scores.size(); ++i)
        {
            if (i==0 || (scores[i-1] != scores[i]))
            {
                ret++;
            }
        }
        
        return ret;
    }
};


int main(int argc, char** argv)
{
    // case 1
    std::vector<int> scores1 = {1, 2, 3};
    // case 2
    std::vector<int> scores2 = {1, 1, 3};
    // case 3
    std::vector<int> scores3 = {1, 4, 2};
    // case 4
    std::vector<int> scores4 = {2, 3, 2};
    // case 5
    std::vector<int> scores5 = {1, 2, 2, 2, 3, 4, 4, 5};

    auto solution = Solution();
    // int unique_num = solution.expectNumber(scores1);
    // int unique_num = solution.expectNumber(scores2);
    // int unique_num = solution.expectNumber(scores3);
    // int unique_num = solution.expectNumber(scores4);
    int unique_num = solution.expectNumber(scores5);
    std::cout << "The unique element number of array: " << unique_num << std::endl;

    return 0;
}
