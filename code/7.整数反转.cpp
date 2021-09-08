/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    // 每次拿到数字的最后一位就可以
    // 判断溢出，每次更新res后除以10，如果跟上次的结果不同就是溢出
    int reverse(int x) {
        int res=0;
        // 注意这里的条件：当x大于0的时候才进入while循环，！x是代表只有x为0的时候才进入
        while(x) {
            if(res < INT_MIN / 10 ||res > INT_MAX / 10)
                return 0;
            int digit = x%10;
            x /=10;
            res = res*10+digit;
        }
        return res;
    }
};
// @lc code=end

