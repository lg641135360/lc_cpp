/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口，只需要知道遍历过程中最大的窗口值，维护[begin,i]
    int findLengthOfLCIS(vector<int>& nums) {
        int begin=0;
        int max_size = 1;
        for(int i=1;i<nums.size();++i) {
            if(nums[i] > nums[i-1]) {
                max_size = max(max_size,i-begin+1);
            }
            else {
                begin = i;
            }
        }
        return max_size;
    }
};
// @lc code=end

