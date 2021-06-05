/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum;
        int mul =1;
        while(n){
            int a = n%10;
            sum+=a;
            mul *= a;
            n /=10;
        }
        return mul-sum;
    }
};
// @lc code=end

