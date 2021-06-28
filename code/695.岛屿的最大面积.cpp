/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};
    // 1.递归的第一种写法:主函数中判断是否进行递归
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
            for(int j = 0;j<grid[0].size();j++)
                if(grid[i][j] == 1)  // 只有当前是陆地（1）时才有必要去递归寻找陆地
                    ans = max(ans,dfs(grid,i,j));
        return ans;
    }

    // 辅助函数，主要进行深度遍历dfs，其他两个参数分别是行号和列号
    int dfs(vector<vector<int>> &grid,int r,int c){
        if(grid[r][c] == 0) return 0;
        // 用过置成0
        grid[r][c] = 0;
        int x,y,area=1;
        for(int i = 0;i<4;i++){
            x = r + direction[i] ,y=c+direction[i+1];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size())
                area += dfs(grid,x,y);
        }
        return area;
    }
};
// @lc code=end

