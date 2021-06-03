/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string str = std::to_string(x);
        int i =0;
        int j = str.size()-1;
        for(;i<=j;i++,j--){
            if(str[i] == str[j]) 
                continue;
            else 
                return false;
        }
        return true;
    }
};
// @lc code=end

