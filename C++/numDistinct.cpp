/**
 * @File    : numDistinct.cpp
 * @Brief   : 不同的子序列
 * @Link    : https://leetcode-cn.com/problems/distinct-subsequences/
 * @Author  : Wei Li
 * @Date    : 2021-09-01
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    // map<string,map<string,int>> num;
    // map<string,map<string,int>> check;
    int numDistinct(std::string s, std::string t)
    {
        if (s.length() < t.length())
            return 0;
        if (s.length() == t.length())
        {
            if (s == t)
                return 1;
            else
                return 0;
        }
        long long int dp[s.length() + 1][t.length() + 1];
        for (int i = s.length(); i >= 0; i--)
        {
            for (int j = t.length(); j >= 0; j--)
            {
                if (j == t.length())
                    dp[i][j] = 1;
                else if (s.length() - i < t.length() - j)
                    dp[i][j] = 0;
                else
                {
                    if (s[i] == t[j])
                        dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                    else
                        dp[i][j] = dp[i + 1][j];
                }
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[0][0];
        // if(s.length()<t.length()) return 0;
        // if(t=="") return 1;
        // if(s.length()==t.length()){
        //     if(s==t) return 1;
        //     else return 0;
        // }
        // if(check[s][t]==1) return num[s][t];

        // int ret=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]==t[0]){
        //         ret+=numDistinct(s.substr(i+1,s.length()-i-1),t.substr(1,t.length()-1));
        //     }
        // }
        // check[s][t]=1;
        // num[s][t]=ret;
        // return ret;
    }
};

int main(int argc, char **argv)
{
    std::string str1 = "rabbbit";
    std::string str2 = "rabbit";

    Solution solution;
    auto num_distinct = solution.numDistinct(str1, str2);
    std::cout << "The solution of this problem is " << num_distinct << std::endl;

    return 0;
}
