/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    // 抖机灵
    // 出自数值分析中的方法
    // 牛顿迭代法 首先随便猜一个近似值 xx，然后不断令 x 等于 x 和 a/x 的平均数，迭代个六七次后 x 的值就已经相当精确了。
    int mySqrt(int x) {
      long r = x;
      while(r*r > x)
        r = (r+x/r) /2;
      return r;
    }
};
// @lc code=end

