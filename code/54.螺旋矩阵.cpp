/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<vector<int>> visited(m.size(),vector<int>(m[0].size(),0));
        vector<int> res;
        int row=0,col=0;
        int t=0;
        for(int p=0;p<m.size()*m[0].size();++p) {
            visited[row][col] = 1;
            res.push_back(m[row][col]);
            // 这里不能直接加，需要判断
            int newRow = row + directions[t][0];
            int newCol = col + directions[t][1];
            if(!isAvailable(m,newRow,newCol,visited)) t=(t+1)%4;  // 不可用时，改变前进方向
            // 这里才需要进行更新坐标
            row += directions[t][0];
            col += directions[t][1];
        }
        return res;
    }
private:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    bool isAvailable(vector<vector<int>> &m,int i,int j,vector<vector<int>> &visited) {
        if(i<0||j<0||i==m.size()||j==m[0].size()||visited[i][j]) 
            return false;
        else return true;
    }

};
// @lc code=end

