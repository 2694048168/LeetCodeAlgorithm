/**
 * @File    : partitionLabels.cpp
 * @Brief   : 划分字母区间 贪心策略
 * @Link    : https://leetcode-cn.com/problems/partition-labels/
 * @Author  : Wei Li
 * @Date    : 2021-07-05
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

// --------------
class Solution
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        int last[26];
        for (size_t i = 0; i < s.size(); ++i)
        {
            last[s[i] - 'a'] = i;
        }

        std::vector<int> partition;
        int start = 0, end = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            end = std::max(end, last[s[i] - 'a']);
            if (i == end)
            {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;        
    }
};


// ----------------------------
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


// -----------------------------
int main(int argc, char** argv)
{
    std::string str = "ababcbacadefegdehijhklij";

    // auto solution = Solution();    
    // Solution solution;
    auto solution = std::make_unique<Solution>();    
    auto vec_partition = solution->partitionLabels(str);
    // auto vec_partition = solution.partitionLabels(str);
    std::cout << "The solution of this problem is : " << std::endl;
    DisplayContents(vec_partition);

    return 0;
}