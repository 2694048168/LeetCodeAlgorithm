/**
 * @File    : verifyPostorder.cpp
 * @Brief   : 二叉搜索树的后序遍历序列
 * @Link    : https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-21
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> res;
    bool verifyPostorder(std::vector<int> &postorder)
    {
        res = postorder;
        return dfs(0, postorder.size() - 1);
    }
    bool dfs(int l, int r)
    {
        if (l >= r)
            return true;   //退出条件
        int root = res[r]; //最后一个点是根结点
        int k = l;         //从最左边开始
        while (k < r && res[k] < root)
            k++;                    //符合左子树的点
        for (int i = k; i < r; i++) //此时的k是右子树的第一个点
        {
            if (res[i] < root) //如果右子树小于根，说明不符合
                return false;
        }
        return dfs(l, k - 1) && dfs(k, r - 1); //逐步缩小范围
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
