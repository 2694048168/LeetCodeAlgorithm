/**
 * @File    : findItinerary.cpp
 * @Brief   : 重新安排行程
 * @Link    : https://leetcode-cn.com/problems/reconstruct-itinerary/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <set>

class Solution
{
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets)
    {
        std::vector<std::string> ans;
        if (tickets.empty())
        {
            return ans;
        }
        std::unordered_map<std::string, std::multiset<std::string>> hash;
        for (const auto &ticket : tickets)
        {
            hash[ticket[0]].insert(ticket[1]);
        }
        std::stack<std::string> s;
        s.push("JFK");
        while (!s.empty())
        {
            std::string next = s.top();
            if (hash[next].empty())
            {
                ans.push_back(next);
                s.pop();
            }
            else
            {
                s.push(*hash[next].begin());
                hash[next].erase(hash[next].begin());
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        for (auto value : element)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// -------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.
    std::vector<std::vector<std::string>> tickets{{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    Solution solution;
    auto find_itinerary = solution.findItinerary(tickets);
    DisplayElement(find_itinerary);

    return 0;
}
