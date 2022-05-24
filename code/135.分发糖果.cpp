/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    // 首先将数组重置为全1，然后从左边扫一遍，将右边比左边大的右加1
    // 然后从右往左遍历，将左边比右边大的全部加1（这里要考虑是否已经比左边那个大，如果已经大了，那么为了取得最小糖果数目，保持原来的数量即可）
    int candy(vector<int>& ratings) {
      int n = ratings.size();
      // 将分配数组初始化为全1
      vector<int> nums(n,1);

      for(int i=1;i<n;i++){
        // 这里是i-1和i而不是i和i+1
        if(ratings[i-1] < ratings[i]) 
          nums[i] = nums[i-1] +1;
      }
      for(int i=n-2;i>=0;i--){
        // 这里是i+1和i，从右边到左边，现在是i，前一个是i+1
        // 但是这里越界了,于是使用i-1和i
        if(ratings[i] > ratings[i+1]) 
          nums[i] = max(nums[i+1]+1,nums[i]);
      }
      return accumulate(nums.begin(),nums.end(),0);
    }
};
// @lc code=end

