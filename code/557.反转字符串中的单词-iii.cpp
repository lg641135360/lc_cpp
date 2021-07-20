/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // string res;
        int start=0,end=0;
        for(int i=0;i<=s.size();++i) {
            if(s[i] != ' ') 
                end ++;
            else {
                reverse(s.begin() + start,s.begin() +end);
                start = end+1;
                end = start;
            }
        }
        reverse(s.begin() + start,s.end());
        return s;
    }
};
// @lc code=end

