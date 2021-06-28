/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        // m若为0，那么
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        // 初始化 已访问数组
        // vector<vector<bool>> visited.resize(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(grid[i][j] == '1'){
                    count++;
                    // 删除与此岛屿相邻接的岛屿
                    eraseIslands(grid,i,j);
                }
        return count;
    }

    // 辅助函数
    void eraseIslands(vector<vector<char>> &grid,int i,int j){
        int m = grid.size(),n=grid[0].size();
        // 当此时下标越界或者 不是陆地时，直接返回即可，不需要处理
        if(i<0 || i == m || j<0 || j==n || grid[i][j] == '0')
            return;
        // 此时是与之邻接的陆地，首先将陆地擦除（置为0）
        grid[i][j] = '0';
        // 递归对四个方向进行同样的擦除操作
        eraseIslands(grid,i-1,j);
        eraseIslands(grid,i+1,j);
        eraseIslands(grid,i,j-1);
        eraseIslands(grid,i,j+1);
    }
};
// @lc code=end

