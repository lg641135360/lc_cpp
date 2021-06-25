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
    // int mySqrt(int x) {
    //   long r = x;
    //   while(r*r > x)
    //     r = (r+x/r) /2;
    //   return r;
    // }

    // 二分查找 求f(x) = x^2-a=0的解
    // 单调函数，观察其函数图像可知：f(0) = 0,f(a) > 0
    // 在[0,a] 使用二分查找。
    int mySqrt(int a) {
        long l = 0, r = a,mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mid*mid == a) return mid;
            else if(mid*mid < a) l = mid+1;
            else r = mid -1;
        }
        return (int)r;
    }
};
// @lc code=end

