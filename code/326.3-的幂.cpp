/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:
    // 将数字转换成3进制，所有位只有一个1就是3的幂次
    // 方法失效
    // 只要n能整除3，就一直整除3，直到最后结果为1
    bool isPowerOfThree(int n) {
      // 只讨论正整数
      if(n<=0) return false; 
      while(n%3==0)
        n /= 3;
      return n == 1;
    }
};
// @lc code=end

