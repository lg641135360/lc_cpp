/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    // vector<int> direction{-1,0,1,0,-1};
    // 1.递归的第一种写法:辅助函数先判定是否越界，合法情况下进入搜索
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     if(grid.empty() || grid[0].empty()) return 0;
    //     int ans = 0;
    //     for(int i = 0;i<grid.size();i++)
    //         for(int j = 0;j<grid[0].size();j++)
    //             if(grid[i][j] == 1)  // 只有当前是陆地（1）时才有必要去递归寻找陆地
    //                 ans = max(ans,dfs(grid,i,j));
    //     return ans;
    // }

    // // 辅助函数，主要进行深度遍历dfs，其他两个参数分别是行号和列号
    // int dfs(vector<vector<int>> &grid,int r,int c){
    //     if(grid[r][c] == 0) return 0;
    //     // 此时grid[r][c] = 1，此时将其置为0，防止进入递归后探测到
    //     grid[r][c] = 0;
    //     int x,y,area=1;
    //     // 4个方向，4叉树
    //     for(int i = 0;i<4;i++){
    //         x = r + direction[i] ,y=c+direction[i+1];
    //         // 限制在矩阵里
    //         if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size())
    //             area += dfs(grid,x,y);
    //     }
    //     return area;
    // }

    // 2.第二种递归写法，辅助函数中先进行搜索，下一步搜索时开始前判断合法性（判断放在辅函数第一行），第二种爷更喜欢（比较简单）
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for(int i = 0;i<grid.size();i++)
            for(int j = 0;j<grid[0].size();j++)
                if(grid[i][j] == 1) 
                    max_area =  max(dfs(grid,i,j),max_area);
        return max_area;
    }

    // 辅助函数
    int dfs(vector<vector<int>> &grid,int r,int c){
        // 将检查边界放在递归函数开头
        if(r<0 || r>=grid.size() || 
            c < 0 || c>=grid[0].size() || grid[r][c] == 0)
            return 0;
        // 此时进入正式的处理阶段
        // 给遍历过的点置为0
        grid[r][c] = 0;
        return 1 + dfs(grid,r+1,c) + dfs(grid,r-1,c) + dfs(grid,r,c+1) + dfs(grid,r,c-1);
    }
};
// @lc code=end

