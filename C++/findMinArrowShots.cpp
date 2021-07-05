/**
 * @File    : findMinArrowShots.cpp
 * @Brief   : 用最少数量的箭引爆气球 贪心策略
 * @Link    : https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * @Author  : Wei Li
 * @Date    : 2021-07-05
*/

#include <iostream>
#include <vector>
#include <algorithm>


// ----------------
class Solution
{
public:
    unsigned int findMinArrowShots(std::vector<std::vector<int>>& points)
    {
        /**
         ** 首先排序，然后使用贪心策略进行遍历数组
         */
        if (points.empty())
        {
            return 0;
        }

        // lambda expression 作为函数对象，一元谓词作为排序的依据
        std::sort(points.begin(), points.end(),
                  [](const std::vector<int>& u, const std::vector<int>& v){ return u[1] < v[1]; }
                );

        int position = points[0][1];
        unsigned int num_shots = 1;
        for (const std::vector<int>& balloon: points)
        {
            // 判断右边界情况
            if (balloon[0] > position)
            {
                position = balloon[1];
                ++num_shots;
            }
        }

        return num_shots;        
    }
};


// -------------------------------
int main(int argc, char** argv)
{
    // test case
    // std::vector<std::vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    // std::vector<std::vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    // std::vector<std::vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    // std::vector<std::vector<int>> points = {{2, 3}, {2, 3}};
    std::vector<std::vector<int>> points = {{1, 2}};

    auto solution = Solution();
    unsigned int num_shoots = solution.findMinArrowShots(points);
    std::cout << "The solution of this problem is : " << num_shoots << std::endl;
    
    return 0;
}
