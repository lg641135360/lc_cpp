/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        // if(!num/10) return num;
        int n = sum_(num);
        while(n/10) n=sum_(n);
        return n;
    }

    int sum_(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};
// @lc code=end

