/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:

    // 1<= number <= 26  直接转换
    // 26 < number <= 52
    string convertToTitle(int n) {
        string res;

        while(n) {
            char c = 'A' + (n-1) % 26 ;
            res = c + res;
            n = (n - 1)/26;
        }

        return res;
    }
};
// @lc code=end

