/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // base case
        int m=mat.size();
        int n=mat[0].size();
        if(m*n!=r*c) return mat;
        queue<int> q;
        for(int i=0;i<mat.size();++i)
            for(int j=0;j<mat[0].size();++j)
                q.push(mat[i][j]);

        vector<vector<int>> res(r,vector<int>(c,0));
        for(int i=0;i<r;++i) 
            for(int j=0;j<c;++j) {
                res[i][j] = q.front();
                q.pop();
            }
                
        return res;
    }
};
// @lc code=end

