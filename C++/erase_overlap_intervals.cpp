/**
 * @File    : erase_overlap_intervals.cpp
 * @Brief   : 无重叠区间 贪心策略
 * @Link    : https://leetcode-cn.com/problems/non-overlapping-intervals/
 * @Author  : Wei Li
 * @Date    : 2021-07-04
*/


//![include]
#include <iostream>
#include <vector>
#include <algorithm>


// ---------------------------------
class Solution
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
    {
        /**
         * 在选择要保留区间时，区间的结尾十分重要：
         * 选择的区间结尾越小，余留给其它区间的空间就越大，就越能保留更多的区间。
         * 因此，采取的贪心策略，优先保留结尾小且不相交的区间。
         * 
         * 具体实现方法为，先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选择的区间不重叠的区间。
         * 这里使用 C++ 的 Lambda，结合 std::sort() 函数进行自定义排序。
         * 
         * 注意 需要根据实际情况判断按区间开头排序还是按区间结尾排序
         */

        // 提高算法的健壮性和鲁棒性
        if (intervals.empty())
        {
            return 0;
        }

        /**C++ 11 & 14 & 17 ，Lambda 函数
         * lambda expression:
         * [capture list] (parameter lsit) -> return type { function body}
         * 
         * 可以忽略参数列表和返回类型，但是必须要有捕获列表和函数体。
         * 捕获列表是一个lambda所在函数中定义的局部变量的列表，通常为空；
         * lambda表达式可以出现在一个函数中，使用其局部变量，但是只能使用那些明确指明的变量，
         * 即通过将局部变量包含在其捕获列表中来指出将会使用这些变量。
         */
        // 向算法 sort 传递 Lambda 函数或者 Lambda 表达式
        // 谓词 predicate 概念
        // 函数对象(Lambda)，利用一个一元谓词进行用户自定义排序
        std::sort(intervals.begin(), intervals.end(), 
                  [](std::vector<int> a, std::vector<int> b) { return a[1] < b[1];}
                );

        // 初始化需要去掉的区间数量为 0
        // 初始化比较的区间为第一个区间
        unsigned int total = 0, prev = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); ++i)
        {
            // 满足前一个区间的尾部值大于当前遍历的区间的首部值，
            // 这说明此两个区间有重叠，需要去掉的数量 + 1
            if (intervals[i][0] < prev)
            {
                ++total;
            }
            // 否则保留当前区间
            // 并将比较的区间更新为当前区间
            else
            {
                prev = intervals[i][1];
            }
        }
        return total;
    }
};
//![solution]


// -------------------------------
int main(int argc, char **argv)
{
    // [test cell]
    // [ [1,2], [2,3], [3,4], [1,3] ]
    // [ [1,2], [1,2], [1,2] ]
    // [ [1,2], [2,3] ]
    // std::vector<std::vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    // std::vector<std::vector<int>> intervals = {{1,2}, {1,2}, {1,2}};
    std::vector<std::vector<int>> intervals = {{1,2}, {2,3}};

    auto solution = Solution();
    auto num_ntervals = solution.eraseOverlapIntervals(intervals);
    std::cout << "The solution of this problem is :" << num_ntervals << std::endl;

    return 0;
}
