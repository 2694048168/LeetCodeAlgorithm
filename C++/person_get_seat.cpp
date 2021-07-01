/**
 * @file    : person_get_seat.cpp
 * @brief   : 飞机座位分配概率，概率分析以及化简(考虑时间复杂度 T(n) )
 * @link    ：https://leetcode-cn.com/problems/airplane-seat-assignment-probability/
 * @author  : Wei Li
 * @date    : 2021-07-01
*/

#include <iostream>
#include <vector>

// probability = f(n) = 1 if n=1 else 1/2
class Solution
{
public:
    double nthPersonGetsNthSeat(unsigned int n)
    {
        // n = [1, 10^5]
        return n == 1 ? 1.0 : 0.5;
    }
};


int main(int argc, char** argv)
{
    // 飞机乘客数 [1, 10^5]
    const unsigned int num_person = 100;

    auto solution = Solution(); 
    auto probability = solution.nthPersonGetsNthSeat(num_person);

    std::cout << "The Probability of the n-th passenger sitting in his seat: " << probability << std::endl;

    return 0;
}