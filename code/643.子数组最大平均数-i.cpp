/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    // 超时了，n^2
    // double findMaxAverage(vector<int>& nums, int k) {
    //     double max_k_avg = INT_MIN;
    //     for(int i=0;i<nums.size()-k+1;++i) {
    //         double curTotal = 0.0;
    //         for(int j=i;j<i+k;++j)
    //             curTotal += nums[j];
    //         max_k_avg = max(max_k_avg,curTotal/k);
    //     }
            
    //     return max_k_avg;
    // }

    // 滑动窗口，sliding window
    double findMaxAverage(vector<int>& nums, int k) { 
        double maxAverage = INT_MIN;
        double curTotal = 0.0;
        for(int i=0;i<k;++i)
            curTotal += nums[i];
        maxAverage = max(maxAverage,curTotal/k);

        // 开始滑动窗口
        for(int i=k;i<nums.size();++i) {
            curTotal -= nums[i-k];
            curTotal += nums[i];
            maxAverage = max(maxAverage,curTotal/k);
        }
        return maxAverage;
    }
};
// @lc code=end

