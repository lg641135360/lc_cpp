/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int res = INT_MIN;
      int n = nums.size()-1;
      // 单独考虑只有一个元素
      if(n==0) return nums[n];

      // 首先排序
      sort(nums.begin(),nums.end());
      
      // 这个数字 肯定 不等于前面那个数和后面那个数字
      if(nums[0] != nums[1]) res = nums[0];

      for(int i = 1;i<n;i++){
        if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
          res = nums[i];
      }
      // 最后一个数字也要单独讨论
      // 当循环结束了，还没有找到，那就是最后一个
      if(res == INT_MIN) res = nums[n];
      return res;
    }

    // A^A^B=B
    // int singleNumber(vector<int>& nums) {
    //   if(!nums.size()) return 0;
    //   int res = nums[0];
    //   for(int i = 1;i<nums.size();i++)
    //     res ^= nums[i];
    //   return res;
    // }
};
// @lc code=end

