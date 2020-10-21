/**
 * LeetCodeLink: https://leetcode-cn.com/problems/assign-cookies/
 * 
 * 455. 分发饼干
 * 
 */

//![include]
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
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
class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) 
    {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        
        int child = 0, cookie = 0;
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