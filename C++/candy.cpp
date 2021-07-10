/**
 * @File    : candy.cpp
 * @Brief   : 分发糖果 贪心策略
 * @Link    : https://leetcode-cn.com/problems/candy/
 * @Author  : Wei Li
 * @Date    : 2021-07-04
*/


//![include]
#include <iostream>
#include <numeric>
#include <vector>
#include <memory>
//![include]

//![solution]
/**
 * 0、只需要简单的两次遍历即可：把所有孩子的糖果数初始化为 1；
 * 1、先从左往右遍历一遍，如果右边孩子的评分比左边的高，
 *    则右边孩子的糖果数更新为左边孩子的糖果数加 1；
 * 2、再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数不大于右边孩子的糖果数，
 *    则左边孩子的糖果数更新为右边孩子的糖果数加 1。
 * 3、通过这两次遍历，分配的糖果就可以满足题目要求了。
 * 
 * 这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一侧的大小关系。
 */
class Solution
{
public:
    int candy(std::vector<int> &ratings)
    {
        size_t size = ratings.size();
        // 若只有一个人，则最少需要一个糖果
        if (size < 2)
        {
            return size;
        }

        // 初始化每个人一个糖果
        std::vector<int> num(size, 1);
        
        // 第一次遍历，从左往右
        for (unsigned int i = 1; i < size; ++i)
        {
            // 如果右边的评分高于左边，则其糖果数量等于其左边的糖果数量 + 1
            if (ratings[i] > ratings[i - 1])
            {
                num[i] = num[i - 1] + 1;
            }
        }

        // 第二次遍历，从右往左
        for (unsigned int i = size - 1; i > 0; --i)
        {
            // 如果左边的评分高于右边，且左边孩子当前的糖果数不大于右边孩子的糖果数，
            // 则左边孩子的糖果数更新为右边孩子的糖果数 + 1
            if (ratings[i] < ratings[i - 1])
            {
                num[i - 1] = std::max(num[i - 1], num[i] + 1);
            }
        }

        // 经过两次遍历之后，则满足题目要求了
        // 贪心策略即为，在每次遍历中，只考虑并更新相邻一侧的大小关系
        return std::accumulate(num.begin(), num.end(), 0); // std::accumulate 可以很方便的求和
    }
};


// ----------------------------------
int main(int argc, char** argv)
{
    // std::vector<int> ratings = {2, 3, 1, 3, 7, 3};
    // std::vector<int> ratings = {1, 0, 2};
    std::vector<int> ratings = {1, 2, 2};

    // auto solution = Solution();  // 基于堆实例化类对象，但是没有智能指针
    auto solution = std::make_unique<Solution>();  // 基于堆实例化类对象，同时使用智能指针
    // Solution solution; // 基于堆栈实例化类对象
    // auto array_candy = solution.candy(ratings);
    // auto array_candy = (*solution).candy(ratings);
    auto array_candy = solution->candy(ratings);
    std::cout << "The solution of this porblem is : " << array_candy << std::endl;
    
    return 0;
}