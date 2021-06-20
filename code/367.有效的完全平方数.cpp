/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    // 暂时只能想到这么个憨憨解法
    bool isPerfectSquare(int num) {
      if(num==1) return true;
      for(long int i = 1;i<=num / 2;i++){
        if(num==i*i) return true;
      }
      return false;
    }
};
// @lc code=end

