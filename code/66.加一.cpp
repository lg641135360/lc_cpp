/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public: 
    // 加一，从最后一个元素开始加法，如果最后一个没有出现%10==0
    // 那就直接返回
    vector<int> plusOne(vector<int>& digits) {

       for(int i = digits.size()-1; i>=0; i--){
           digits[i]++;
           digits[i] %=10;
           if(digits[i] != 0) return digits;
       } 
        // 如果到了这一行都没有返回，那么说明每一列都进位9999
        digits.insert(digits.begin(),1);
        return digits;
    }
};
// @lc code=end

