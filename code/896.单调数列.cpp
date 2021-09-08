/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
public:
    // 暴力破解
    bool isMonotonic(vector<int>& nums) {
        if(nums[nums.size()-1] - nums[0] >= 0){
            for(int i=0,j=i+1;j<nums.size();i++,j++){
                if(nums[i] > nums[j]) return false;
            }
            return true;
        }
        else{
            for(int i=0,j=i+1;j<nums.size();i++,j++){
                if(nums[i] < nums[j]) return false;
            }
            return true;
        }
    }


    // bool isMonotonic(vector<int>& nums) {

    // }
};
// @lc code=end

