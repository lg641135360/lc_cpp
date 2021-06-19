/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    // 只要n能整除4，那就一直除以4
    bool isPowerOfFour(int n) {
      if(n<=0) return false;
      while(n%4==0)
        n /= 4;
      return n==1;
    }
};
// @lc code=end

