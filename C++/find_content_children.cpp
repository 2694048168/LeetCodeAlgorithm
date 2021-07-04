/**
 * @File    : find_content_children.cpp
 * @Brief   : 分发饼干 贪心策略(每个局部之间要求独立，不相关)
 * @Link    : https://leetcode-cn.com/problems/assign-cookies/
 * @Author  : Wei Li
 * @Date    : 2021-07-04
*/

//![include]
#include <iostream>
#include <vector>
#include <algorithm>
//![include]


//![solution]
/**
 * 贪心算法或贪心思想采用贪心的策略，保证每次操作都是局部最优的，
 * 从而使最后得到的结果是全局最优的.
 * 
 * 至于具体实现，因为需要获得大小关系，一个便捷的方法就是把孩子和饼干分别排序。
 * 这样就可以从饥饿度最小的孩子和大小最小的饼干出发，计算有多少个对子可以满足条件。
 * 
 * 注意 对数组或字符串排序是常见的操作，方便之后的大小比较。
 * 注意 若谈论的是对连续空间的变量进行操作，并不会明确区分数组和字符串，
 * 因为本质上都是在连续空间上的有序变量集合。
 */
class Solution 
{
public:
    int findContentChildren(std::vector<int>& children, std::vector<int>& cookies) 
    {
        std::sort(children.begin(), children.end());
        std::sort(cookies.begin(), cookies.end());
        
        unsigned int child = 0, cookie = 0;
        while (child < children.size() && cookie < cookies.size()) 
        {
            // 满足条件的情况
            if (children[child] <= cookies[cookie])
            {
                ++child;
            } 
            ++cookie;
        }
        return child;
    }
};


// --------------------------------
int main(int argc, char** argv)
{
    // std::vector<int> children = {1, 3, 4, 2};
    // std::vector<int> cookies = {6, 2, 3, 5};

    std::vector<int> children = {1, 3, 2};
    std::vector<int> cookies = {1, 1};

    auto solution = Solution();
    auto num_child = solution.findContentChildren(children, cookies);
    std::cout << "The solution of this problem is : " << num_child << std::endl;

    return 0;
}
