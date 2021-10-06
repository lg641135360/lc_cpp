/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution {
public:
    // tick tock
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;

        int tick = 0;
        for(int j=0;j<n;) {
            if(tick % 2 == 0) {
                result.push_back(nums[j]);
                tick ++;
            }
            else {
                result.push_back(nums[j+n]);
                j++;
                tick++;
            }
        }

        return result;
    }
};
// @lc code=end

