/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // double myPow(double x, int n) {
    //     return pow(x,n);
    // }

    // 暴力超时
    // double myPow(double x, int n) {
    //     double res = 1;
    //     if(n==0) return (double)1;
    //     else if(n>=1) {
    //         for(int i=1;i<=n;++i)
    //             res *= x;
    //     }
    //     else {
    //         for(int i=1;i<=abs(n);++i)
    //             res *= x;
    //             res = 1/res;
    //     }
    //     return res;
    // }

    // 递归分治法 超时
    // double myPow(double x, int n) { 
    //     // 最后递归结果
    //     // 递归要有最终条件
    //     if(n==0)return 1; // n=0直接返回1
    //     else if(n<0){   				//n<0时 x的n次方等于1除以x的-n次方分 -n负负得正
    //         return 1/myPow(x,-n);
    //     }
    //     if(n%2){    // n是奇数时 x的n次方 = x*x的n-1次方 ===>转化为偶数
    //         return x*myPow(x,n-1);
    //     }
    //     return myPow(x*x,n/2); // n是偶数，使用分治，一分为二，等于x*x的n/2次方 （x*x）的n/2次方
    // }
    
    // 隐式类型转换
    // 偶数次幂少算一半
    double myPow(double x, long n) { 
        if (!n) return 1;
        if (n < 0) n = -n, x = 1 / x;
        return n & 1 ? x * myPow(x * x, n >> 1) : myPow(x * x, n >> 1);
    }

};
// @lc code=end

