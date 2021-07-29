/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n % 2;
        int curr = prev;
        while(n) {
            curr = (n/2)%2; 
            if(prev ^ curr == 0) return false;
            else {
                n/=2;
                prev = curr;
            }
        }
        return true;
    }
};
// @lc code=end

