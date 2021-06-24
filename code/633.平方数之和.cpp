/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    // 勾股定理a^2 + b^2 = c
    // a^2∈[0,c]
    bool judgeSquareSum(int c) {
        for(long a=0;a*a<=c;a++){
            double b = sqrt(c-a*a);
            if(b==int(b))
                return true;
        }
        return false;
    }
};
// @lc code=end

