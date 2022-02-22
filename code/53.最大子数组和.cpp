/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    // DP[i] 以i为结束位置的最大子数组之和
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int dp[n];
    //     if(0 == n) 
    //         return 0;
        
    //     for(int i=0;i<n;i++)
    //         dp[i] = INT_MIN;   // 初始化状态
        
    //     // 初始化状态
    //     dp[0] = nums[0];

    //     int res = dp[0];
    //     for(int i=1;i<n;i++)
    //     {
    //         dp[i] = max(nums[i],dp[i-1] + nums[i]);
    //         res = max(dp[i],res);
    //     }
    //     return res;
    // }

    // 状态压缩，DP[i]只与DP[i-1]有关则只用存储两个整型变量
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(0==n) return 0;

        int dp_0 = nums[0],dp_1 = 0; // 初始化状态

        int res = dp_0;
        for(int i=1;i<n;i++)
        {
            dp_1 = max(nums[i],dp_0+nums[i]);
            dp_0 = dp_1;
            res  = max(res,dp_1);
        }
        return res;
    }
};
// @lc code=end

