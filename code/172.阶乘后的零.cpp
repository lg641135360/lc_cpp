/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    // 先计算出n! 
    // 依次除以10 计数
    // 计算到13就超出范围
    // int trailingZeroes(int n) {
    //     // n==0
    //     if(!n) return n;

    //     // compute n!
    //     int n_1 = 1;
    //     for(int i=1;i<=n;++i)
    //         n_1 *= i;

    //     // count the zero number
    //     int zero_count = 0;
    //     bool flag = false;
    //     if(n_1 % 10 == 0) {
    //         flag = true;
    //         zero_count++;
    //         count_(zero_count,n_1/10,flag);
    //     }
    //     else zero_count = 0;
    //     return zero_count;
    // }   

    // void count_(int &zero_count, int n, bool flag) {
    //     while(n) {
    //         if(n%10 == 0)
    //             zero_count++;
    //         else return ;
    //         n /= 10;
    //     }
    // }

    // 为了计算尾数0的数量，首先需要想清楚什么会产生尾数0？
    // 一个数字乘以10会有一个尾数0加入
    // 找出 阶乘的表达式 中会出现多少个10
    // 由于10=2*5，而且还有一堆2（每个偶数至少有一个2），只需要计算5的数量
    // 哪些数字会贡献一个5。好吧，简单来说就是5的倍数
    // 只有5的倍数才会贡献一个以上的5
    // 尝试一些例子
    // n / 5 + n / 25 + n / 125 + .... 
    // 5的倍数贡献一个5，25的倍数再贡献一个
    int trailingZeroes(int n) {
        int count = 0;
        // 这里找到所有是5倍数的i
        for(long long i=5;n/i;i*=5)
            count+=n/i;
        return count;       
    }
};
// @lc code=end

