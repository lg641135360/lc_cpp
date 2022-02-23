/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // // dp[i][j]表示从(0,0)位置到(i,j)位置的最大路径个数
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,0));
    //     // vector<vector<int>> visited(m,vector<int>(n,0));
        
    //     // base case 该位置只能由前一列/前一行得到，只有一种路径
    //     for(int i=0;i<m;++i) 
    //         dp[i][0] = 1;
    //     for(int i=0;i<n;++i)
    //         dp[0][i] = 1;
        
    //     for(int i=1;i<m;++i)
    //         for(int j=1;j<n;++j)
    //             dp[i][j] = dp[i][j-1] + dp[i-1][j];
    //             // 这里dp[i][j] 只与dp[i-1][j] + dp[i][j-1]有关
    //     return dp[m-1][n-1];
    // }

    int uniquePaths(int m, int n) {
        int dp[m][n];

        // 初始化状态
        for(int i=0;i<m;i++) dp[i][0] = 1;
        for(int j=0;j<n;j++) dp[0][j] = 1;

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }

// private:
//     vector<vector<int>> directions = {{0,1},[1,0]};
};
// @lc code=end

