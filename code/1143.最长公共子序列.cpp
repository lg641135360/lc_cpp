/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                // 当前字符 i-1，i从0开始
                if(text2[j-1] == text1[i-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

