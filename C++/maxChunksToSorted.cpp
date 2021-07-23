/**
 * @File    : maxChunksToSorted.cpp
 * @Brief   : 最多能完成排序的块
 * @Link    : https://leetcode-cn.com/problems/max-chunks-to-make-sorted/
 * @Author  : Wei Li
 * @Date    : 2021-07-23
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxChunksToSorted(std::vector<int> &arr)
    {
        int chunks = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            cur_max = std::max(cur_max, arr[i]);
            if (cur_max == i)
            {
                ++chunks;
            }
        }
        return chunks;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> vec{4, 3, 2, 1, 0};
    std::vector<int> vec{1, 0, 2, 3, 4};

    Solution solution;
    auto max_sorted_num = solution.maxChunksToSorted(vec);
    std::cout << "The solution of this problem is " << max_sorted_num << std::endl;

    return 0;
}
