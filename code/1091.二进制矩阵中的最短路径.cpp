/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();

        // base case：如果起点终点不可达，直接返回-1
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1)
            return -1;

        queue<vector<int>> que;
        // (0,0)位置已走1步
        grid[0][0] = 1;
        que.push({0, 0});
        // 第二个条件是最快走到右下角后退出循环
        while (!que.empty() && grid[row - 1][col - 1] == 0)
        {
            vector<int> xy = que.front();
            que.pop();
            int preLength = grid[xy[0]][xy[1]]; // 当前点的路径长度
            for (int i = 0; i < 8; i++)
            {
                int newX = xy[0] + directions[i][0];
                int newY = xy[1] + directions[i][1];
                if (inGrid(newX, newY) && grid[newX][newY] == 0)
                {
                    que.push({newX, newY});
                    grid[newX][newY] = preLength + 1; // 下一个点路径加一
                }
            }
        }
        return grid[row - 1][col - 1] == 0 ? -1 : grid[row - 1][col - 1];
    }

private:
    int directions[8][2] = {{0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int row, col;

    bool inGrid(int x, int y)
    {
        return x >= 0 && x < row && y >= 0 && y < col;
    }
};
// @lc code=end
