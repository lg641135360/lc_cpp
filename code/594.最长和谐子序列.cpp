/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口
    int findLHS(vector<int>& nums) {
        // 可以随便挑选，没有要求输出具体的子序列
        // 考虑排序
        sort(nums.begin(),nums.end());
        int begin=0;
        int max_size = 0;
        for(int i=1;i<nums.size()&&begin<nums.size();) {
            // 此时nums[i]是最大值,nums[begin]是最小值
            if(nums[i] - nums[begin] == 1) {
                max_size = max(max_size,i-begin+1);
                ++i;
            }
            else if(nums[i] - nums[begin] > 1){
                begin ++;
            }
            else {   // nums[begin] == nums[i]
                ++i;
            }
        }
        return max_size;
    }
};
// @lc code=end

