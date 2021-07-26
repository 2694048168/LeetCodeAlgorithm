/**
 * @File    : maxPoints.cpp
 * @Brief   : 直线上最多的点数
 * @Link    : https://leetcode-cn.com/problems/max-points-on-a-line/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int maxPoints(std::vector<std::vector<int>> &points)
    {
        std::unordered_map<double, int> hash; // <斜率, 点个数>
        int max_count = 0, same = 1, same_y = 1;
        for (int i = 0; i < points.size(); ++i)
        {
            same = 1, same_y = 1;
            for (int j = i + 1; j < points.size(); ++j)
            {
                if (points[i][1] == points[j][1])
                {
                    ++same_y;
                    if (points[i][0] == points[j][0])
                    {
                        ++same;
                    }
                }
                else
                {
                    double dx = points[i][0] - points[j][0], dy = points[i][1] -
                                                                  points[j][1];
                    ++hash[dx / dy];
                }
            }
            max_count = std::max(max_count, same_y);
            for (auto item : hash)
            {
                max_count = std::max(max_count, same + item.second);
            }
            hash.clear();
        }
        return max_count;
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    // std::vector<std::vector<int>> points{{1, 1}, {2, 2}, {3, 3}};
    std::vector<std::vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

    Solution solution;
    auto max_point = solution.maxPoints(points);
    std::cout << "The solution of this problem is " << max_point << std::endl;

    return 0;
}
