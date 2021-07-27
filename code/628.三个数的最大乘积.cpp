/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    // 暴力超时了
    // int maximumProduct(vector<int>& nums) {
    //     int max_res = INT_MIN;
    //     for(int i=0;i<nums.size();++i) 
    //         for(int j=i+1;j<nums.size();++j)
    //             for(int p=j+1;p<nums.size();++p)
    //                 max_res=max(max_res,nums[i]*nums[j]*nums[p]);
    //     return max_res;
    // }


    // 贪心，大数乘在一起才是大数字
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0] * nums[1] * nums[n - 1]);
    }
};
// @lc code=end

