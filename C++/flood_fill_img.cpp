/**
 * @file flood_fill_img.cpp
 * @author Wei Li (weili_yzzcq@163.com)
 * @brief 图像渲染
 * @cite https://leetcode.cn/problems/flood-fill/
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <typeinfo>
#include <cstdint>
#include <vector>
#include <queue>
#include <utility>


/**
 * @brief 有一幅以 m x n 的二维整数数组表示的图画 image, 其中 image[i][j] 表示该图画的像素值大小,
 * 给定三个整数 x, y, pixel_value, (x, y)表示初始像素位置, 对像素 image[x][y] 开始对图像进行上色填充 pixel_value.
 * 
 * 为了完成上色, 从初始像素开始, 记录初始坐标的 '上下左右' 四个方向上 '像素值与初始坐标相同' 的相连像素点,
 * 接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，
 * 重复该过程, 将所有有记录的像素点的颜色值改为 pixel_value, 最后返回 经过上色渲染后的图像.
 * 
 * BFS, 广度优先搜索 思路:
 * 1. 首先找到初始节点，给它染色，这个初始节点当作第一层;
 * 2. 找到初始节点周围四个节点，给它们染色 (符合条件的才能染)，这四个节点当作第二层;
 * 3. 再找到这四个节点周围八个节点，给它们染色，这八个节点当作第三层;
 * 5. 重复以往，层层递进，直到找不到符合要求的节点;
 * 思路很好理解，就是一个从中间向外扩散的过程, 在实现中需要 '队列'的辅助('广度优先搜索' 和 '队列' 是好友)
 * 
 * 利用 队列 实现 广度优先搜索:
 * 1. 设置一个队列，先把初始点添加进去;
 * 2. 规定每次从队列取出一个坐标;
 * 3. 对这个坐标染色，并且把这个坐标的邻居（符合要求且不重复的好邻居），放到队列中;
 * 4. 当这个队列为空的时候，说明染色完成;
 * 因为队列每次取出的是最后的，而每次添加的是放在最前面，所以每次先处理的都是层级最少的，
 * 最接近初始点的，然后慢慢扩大，这样就实现了 广度优先搜索
 * 
 */
class Solution
{
public:
    // std::vector<std::vector<unsigned int>> floodFill(std::vector<std::vector<unsigned int>> &image, unsigned int x, unsigned int y, unsigned int pixel_value)
    void floodFill(std::vector<std::vector<unsigned int>> &image, unsigned int x, unsigned int y, unsigned int pixel_value)
    {
        /* 记录当前索引的像数值，上色后改变了 */
        unsigned int current_pixel = image[x][y];

        /* special case 起始颜色和目标颜色相同，则直接返回原图
        该特殊情况一定要处理，否则直接进入无穷循环 */
        if (current_pixel == pixel_value)
        {
            // return image;
            return;
        }
        
        /* 在实现中需要 '队列'的辅助('广度优先搜索' 和 '队列' 是好友) */
        std::queue<std::pair<unsigned int, unsigned int>> coordinates_que;
        coordinates_que.emplace(x, y);
        image[x][y] = pixel_value;

        /* 'top-bottom-left-right' 
            current_pixel: image[x][y];
            top_pixel: image[x - 1][y + 0];
            bottom_pixel: image[x + 1][y + 0];
            left_pixel: image[x + 0][y - 1];
            right_pixel: image[x + 0][y + 1];
        */
        const int dx[4] = {1, 0, 0, -1};
        const int dy[4] = {0, 1, -1, 0};
        // const int dx[4] = {-1, 1, 0, 0};
        // const int dy[4] = {0, 0, -1, 1};
        unsigned int num_rows = image.size(), num_cols = image[0].size();

        while (!coordinates_que.empty()) /* 当这个队列为空的时候，说明染色完成 */
        {
            // 取出队列头部的坐标对，并弹出队列
            unsigned int x = coordinates_que.front().first, y = coordinates_que.front().second;
            coordinates_que.pop();

            /* how to loop 'top-bottom-left-right' according to the current coordinates */
            for (size_t idx = 0; idx < 4; ++idx) /* 从中间向外进行层层扩散的过程 */
            {
                unsigned int mu_x = x + dx[idx], mu_y = y + dy[idx];
                /* 边界判断 and 满足上色条件判断 */
                if ((mu_x >= 0 && mu_x < num_rows) &&  (mu_y >= 0 && mu_y < num_cols) && (image[mu_x][mu_y] == current_pixel))
                {
                    // add to coordinates queue
                    coordinates_que.emplace(mu_x, mu_y);
                    // color this pixel-coordinates 并将该方格的颜色更新，以防止重复入队
                    image[mu_x][mu_y] = pixel_value;
                }
            }
        }
        // return image;
    }
};


/**
 * @brief template function for print the element value on the terminal(std::output)
 * 
 * @tparam Type 
 * @param container the container from standard C++
 */
template <typename Type>
void printElement(const Type& container)
{
    for (const auto& element: container)
    {
        // std::cout << typeid(element).name() << std::endl;
        for (const auto& value: element)
        {
            std::cout << value << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


// ---------------------------------------
int main(int argc, char const *argv[])
{
    // unsigned int init_x = 1, init_y = 1;
    unsigned int init_x = 0, init_y = 0;
    unsigned int pixel_value = 2;
    std::cout << pixel_value << std::endl;
    std::vector<std::vector<unsigned int>> image {{1,1,1},
                                         {1,1,0},
                                         {1,0,1}};

    std::cout << typeid(image).name() << std::endl;

    printElement(image);
    Solution solution;
    // auto colored_img = solution.floodFill(image, init_x, init_y, pixel_value);
    // printElement(colored_img);

    solution.floodFill(image, init_x, init_y, pixel_value);
    printElement(image);
    
    return 0;
}
