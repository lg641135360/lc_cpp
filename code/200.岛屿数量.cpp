/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:

    // int numIslands(vector<vector<char>>& grid) {
    //     // m若为0，那么
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int count = 0;
    //     // 初始化 已访问数组
    //     // vector<vector<bool>> visited.resize(grid.size(),vector<bool>(grid[0].size(),false));
    //     for(int i=0;i<m;i++)
    //         for(int j = 0;j<n;j++)
    //             if(grid[i][j] == '1'){
    //                 count++;
    //                 // 删除与此岛屿相邻接的岛屿
    //                 eraseIslands(grid,i,j);
    //             }
    //     return count;
    // }

    // // 辅助函数
    // void eraseIslands(vector<vector<char>> &grid,int i,int j){
    //     int m = grid.size(),n=grid[0].size();
    //     // 当此时下标越界或者 不是陆地时，直接返回即可，不需要处理
    //     if(i<0 || i == m || j<0 || j==n || grid[i][j] == '0')
    //         return;
    //     // 此时是与之邻接的陆地，首先将陆地擦除（置为0）
    //     grid[i][j] = '0';
    //     // 递归对四个方向进行同样的擦除操作
    //     eraseIslands(grid,i-1,j);
    //     eraseIslands(grid,i+1,j);
    //     eraseIslands(grid,i,j-1);
    //     eraseIslands(grid,i,j+1);
    // }

    int numIslands(vector<vector<char>>& grid) {
        int islands_num = 0;
        vector<vector<int>> mark(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'&&mark[i][j]==0){
                    bfs(mark,grid,i,j);
                    islands_num ++;
                }
            }
        return islands_num;
    }

    void dfs(vector<vector<int>> &mark,vector<vector<char>> &grid,int x,int y) {
        // 首先标记当前位置已被搜索
        mark[x][y] = 1;
        // 方向数组 ： 左右 上下
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        // 拓展四个方向
        for(int i = 0;i<4;++i){
            int newx = x+dx[i];
            int newy = y+dy[i];
            // 跳过无效位置
            if(newx>=grid.size() || newx<0 ||
                newy>=grid[0].size()||newy<0)
                continue;
            // 有个方向的没有被搜索且是陆地时继续深搜
            if(mark[newx][newy]==0&&grid[newx][newy]=='1')
                dfs(mark,grid,newx,newy);
        }        
    }
    void bfs(vector<vector<int>> &mark,vector<vector<char>> &grid,int x, int y) {
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        queue<pair<int,int>> q;      // 宽度优先搜索队列
        q.push(make_pair(x,y));      // （x，y）入队列，并做标记
        mark[x][y] = 1;
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;   // 取队头元素
            q.pop();                // 推出一个
            for(int i = 0;i<4;++i){
                int newx = x+dx[i];
                int newy = y+dy[i];
                // 跳过无效位置
                if(newx>=grid.size() || newx<0 ||
                    newy>=grid[0].size()||newy<0)
                    continue;
                // 有个方向的没有被搜索且是陆地时继续深搜
                if(mark[newx][newy]==0&&grid[newx][newy]=='1'){
                    q.push(make_pair(newx,newy));
                    mark[newx][newy] = 1;   // 做标记
                }                    
            }   
        }
    }
};
// @lc code=end

