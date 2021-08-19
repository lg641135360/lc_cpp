/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    // 子数组要求连续 ==> 滑动窗口
    // [0,2]无法解决
    // int maxProduct(vector<int>& nums) {
    //     if(nums.size() == 0) return 0;
    //     if(nums.size() == 1) return nums[0];
    //     int begin = 0;
    //     int max_ = nums[begin];
    //     for(int i=1;i<nums.size();) {
    //         if(max_*nums[i] >= max_) {
    //             max_ = max(max_,multiply(nums,begin,i));
    //             i++;
    //         }
    //         else {
    //             begin = i;
    //             i = begin+1;
    //         }
    //     }
    //     return max_;
    // }

    // int multiply(vector<int> &nums,int begin,int i) {
    //     int tmp = 1;
    //     for(int j =begin;j<=i;j++) {
    //         tmp *= nums[j];
    //     }
    //     return tmp;
    // }

    // dp[i]代表以i位置为结束的子数组最大乘积
    // [-2,3,-4] 无法考虑到
    // 2^3 = 8中选择，而不是在以nums[n-1]结尾中选最大的
    // 这里的dp[i]定义出问题
    // int maxProduct(vector<int>& nums) {
    //     vector<int> dp(nums.size(),0);
    //     // base case 
    //     dp[0] = nums[0];

    //     for(int i=1;i<nums.size();++i) {
    //         dp[i] = max(dp[i-1]*nums[i],nums[i]);
    //     }

    //     // return dp[nums.size()-1];
    //     // 应该返回dp数组中最大元素
    //     int max_ = dp[0];
    //     for(int i=1;i<dp.size();++i) {
    //         if(dp[i] > max_)
    //             max_ = dp[i];
    //     }
    //     return max_;
    // }

    // dp[i]表示范围以i结尾的子数组乘积中最大值
    // 这里状态之间没找到转换的公式
    // 放弃dp
    // int maxProduct(vector<int>& nums) {
    //     vector<int> dp(nums.size(),0);
    //     // base case 
    //     dp[0] = nums[0];

    //     for(int i=1;i<nums.size();++i) {
    //         dp[i] = max(dp[i-1]*nums[i],dp[i-1]);
    //     }

    //     return dp[nums.size()-1];

    // }

    // 类似最大子列和 在线处理
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans = INT_MIN;
        int max_v = 1,min_v=1;
        for(int i=0;i<n;i++){
            if(nums[i] <0) swap(max_v,min_v);
            max_v = max(max_v*nums[i],nums[i]);
            min_v = min(min_v*nums[i],nums[i]);
            ans = max(max_v,ans);
        }
        return ans;
    }
};
// @lc code=end

