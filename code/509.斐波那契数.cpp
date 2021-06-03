/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        // 此时r是n=1时候的斐波那契数
        // 1 1 1 2 3 5
        // 但是题目要求是 0 1 1 2所以少算一位就行
        // 特殊处理以下0的情况
        if(!n) return 0;
        int p=0,q=0,r=1;
        for(int i = 1;i<n;++i){
            p =q;
            q = r;
            r=p+q ;
        }
        
        return r;
    }
};
// @lc code=end

