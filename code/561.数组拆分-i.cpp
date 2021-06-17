/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      // 注意这里初始化为0，不初始化可能为一个随机值
      int res = 0;
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size();i+=2){
        res += nums[i];
      }
        
      return res;
    }
};
// @lc code=end

