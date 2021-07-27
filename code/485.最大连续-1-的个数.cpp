/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_size = 0;
        int begin = 0;

        // base case
        if(nums.size() == 1)
            return nums[0] == 1;

        find_1_begin(nums,begin,0);
        for(int i=begin;i<nums.size();) {
            if(nums[i] == 1) {
                max_size = max(max_size,i-begin+1);
                ++i;
            }
            else {
                find_1_begin(nums,begin,i);
                i = begin+1;
            } 
        }
        return max_size;
    }

    void find_1_begin(vector<int> &nums,int &begin,int i) {
        for(int j=i;j<nums.size();j++) 
            if(nums[j] == 1) {
                begin = j;
                return;
            }
        // 没找到1
        begin = nums.size();
    }
};
// @lc code=end

