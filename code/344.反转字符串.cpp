/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    // 调库
    // void reverseString(vector<char>& s) {
    //     reverse(s.begin(),s.begin()+s.size());
    // }

    // 自己实现
    void reverseString(vector<char>& s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--) {
            swap(s[i],s[j]);
        }
    }
};
// @lc code=end

