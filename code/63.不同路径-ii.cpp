/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    // dp[i][j]代表（0，0）位置到（i，j）位置的最多路径数
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));

        // base case
        int index_obs = -1;
        for(int i=0;i<m;++i) {
            if(obstacleGrid[i][0]) {
                index_obs = i;
                dp[i][0] =0;
                break;
            }
            else dp[i][0] = 1;
        }
        if(index_obs != -1) 
            for(int i=index_obs+1;i<m;++i)
                dp[i][0] = 0;

        index_obs = -1;
        for(int i=0;i<n;++i) {
            if(obstacleGrid[0][i]) {
                index_obs = i;
                dp[0][i] =0;
                break;
            }
            else dp[0][i] = 1;
        }
        if(index_obs != -1) 
            for(int i=index_obs+1;i<n;++i)
                dp[0][i] = 0;
        
        for(int i=1;i<m;++i)
            for(int j=1;j<n;++j) {
                // dp[i][j] == 0表示不可达
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];
    }
};
// @lc code=end

