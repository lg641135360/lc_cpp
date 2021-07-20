/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    // bool checkPerfectNumber(int num) {
    //     set<int> s;
    //     for(int i=1;i<num;++i)
    //         if(num%i == 0)
    //             s.insert(i);
    //     int res = 0;
    //     for(auto i:s)
    //         res += i;
    //     return res == num;
    // }

    bool checkPerfectNumber(int num) { 
        int sum=1;
        for(int i=2;i<=sqrt(num);i++) 
            if(num%i==0) 
                sum += i + (i==num/i ? 0 : num/i);
        return sum==num && num!=1;
    }
};
// @lc code=end

