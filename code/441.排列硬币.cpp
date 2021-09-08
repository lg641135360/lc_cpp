/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
      long long int sum = 0;
      int floor = 0;
      for(int i = 1;sum+i<=n;i++){
        sum+=i;
        floor++;
      }
      return floor;
    }
};
// @lc code=end

