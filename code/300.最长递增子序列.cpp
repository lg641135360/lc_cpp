/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size(),0);
    //     dp[0] = 1;
    //     int LIS = 1;  // 将最大的选择出来
    //     for(int i =1;i<nums.size();++i){
    //         dp[i] = 1;  // 基准值（有的元素为结尾长度就是1）
    //         for(int j=0;j<i;++j)
    //             if(nums[i] > nums[j]&&dp[i]<dp[j]+1)
    //                 dp[i] = dp[j] + 1;
    //         if(LIS<dp[i])
    //             LIS = dp[i];
    //     }
    //     return LIS;
    // }

    // DP[i]表示从0开始到i结束的最长递增子序列长度
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(0==n) return 0;
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i] = 1; // 初始化状态


        int res = 1;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<j;i++)
            {
                if(nums[i] < nums[j])
                    dp[j] = max(dp[i]+1,dp[j]);
                    res = max(dp[j],res);
            }
        }
        return res;
    }
};
// @lc code=end

