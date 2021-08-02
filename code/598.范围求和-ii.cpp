/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
public:
    // 超时
    // int maxCount(int m, int n, vector<vector<int>>& ops) {
        
    //     vector<vector<int>> mat(m,vector<int>(n,0));
    //     int count = 0;
    //     for(int i=0;i<ops.size();++i) {
    //         for(int p=0;p<ops[i][0];++p) 
    //             for(int q=0;q<ops[i][1];++q)
    //                 mat[p][q] ++;
    //     }
    //     for(int i=0;i<m;++i) 
    //         for(int j=0;j<n;++j)
    //             if(mat[i][j] == ops.size())
    //                 count++;
    //     return count;
    // }

    // 大小只跟操作中最小单元和操作的长度有关
    int maxCount(int m, int n, vector<vector<int>>& ops) { 
        if(!ops.size()) return m*n;
        int x = INT_MAX;
        int y = INT_MAX;
        for(int i=0;i<ops.size();++i) {
            x = min(x,ops[i][0]);
            y = min(y,ops[i][1]);
        }
        return x*y;
    }
};
// @lc code=end

