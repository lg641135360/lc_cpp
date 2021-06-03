/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public: 
    // 简答使用暴力递归，不出意外，溢出了
    // int tribonacci(int n) {
    //     if(!n) return 0;
    //     if(n==1|| n==2) return 1;
    //     return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    // }

    // f（n）只跟前面三个数字有关
    int tribonacci(int n) {
        // 处理一哈特殊情况
        if(!n) return 0;
        int o = 0,p=0,q=0,r=1;
        // 注意边界，少算一个
        for(int i = 1;i<n;i++){
            o = p;
            p=q;
            q=r;
            r=o+p+q;
        }
        return r;
    }
};
// @lc code=end

