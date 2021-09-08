/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n,vector<int>(n,0));
        vector<vector<int>> visited(n,vector<int>(n,0));
        int row=0,col=0,t=0;
        for(int i=0;i<n*n;++i) {
            visited[row][col] = 1;
            m[row][col] = i+1;
            int newRow = row + directions[t][0];
            int newCol = col + directions[t][1];
            if(newRow<0||newCol<0||newRow==n||newCol==n||visited[newRow][newCol]) 
                t = (t+1) % 4;
            row += directions[t][0];
            col += directions[t][1];
        }
        return m;
    }

private:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
};
// @lc code=end

