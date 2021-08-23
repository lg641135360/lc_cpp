/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    // 方法可以，但是超时了824883294
    // int countDigitOne(int n) {
    //     if(n==0) return 0;
    //     int count = 0;
    //     for(int i=1;i<=n;i++) {
    //         compute1(i,count);
    //     }
    //     return count;
    // }

    // // 采用遍历的方式计算
    // void compute(int i,int &count) {
    //     while(i) {
    //         int tmp = i%10;
    //         if(tmp == 1)
    //             count++;
    //         i /= 10;
    //     }
    // }

    // // 采用string的方法
    // void compute1(int i,int &count){
    //     string s = to_string(i);
    //     for(int i=0;i<s.size();++i){
    //         if(s[i] == '1')
    //             count++;
    //     }
    // }

    // 寻找数字规律
    // 以3413为例：
    // 个位出现1:每10个数字出现一个1，3413/10 = 341，341*10 < 3413 
    // 少算一个 各位的1 341+1
    // 十位:3413/100 = 34 34*100<3413 34 +1，而十位1的情况有10-19 10种情况 于是加上这35*10
    // 百位：3413/1000 = 3 3*1000<3413 于是4*100个
    // 千位：3413/10000 = 0 ,0*10000<3413 有1*10000个
    // int countDigitOne(int n) {
    //     int e = 0;  // 计数
    //     int r=0;    // 后面的数
    //     for(int i=0;n!=0;i++) {
    //         int m=n/10;     // 有几个10
    //         if(m*10+1<n) 
    //             m++;        // 3411情况
    //         else if(m*10+1==n)  // 3413
    //             e += r+1;
    //         e+=(m*pow(10,i));
    //         r+=(n%10*pow(10,i));
    //         n/=10;
    //     }
    //     return e;
    // }

    int countDigitOne(int n) {
        long long t = 1; // 10的i次方
        int res = 0;
        for(int i = 0; t <= n; t *= 10, i++) 
            res += n / (t * 10) * t + min(max(0LL, n % (t * 10) - t + 1), t);
        return res;
    }
};
// @lc code=end

