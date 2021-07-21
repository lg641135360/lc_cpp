/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_index = s.size()-1;
        if(s.size() == 1) {
            if(s[0] == ' ')
                return 0;
            else 
                return 1;
        }
        for(int i=s.size()-1;i>=0;--i) {
            if(s[i] == ' ') {
                if(i == s.size()-1)
                    continue;
                else last_index = i;
            } 
        }
            
        return s.size()-1-last_index;

            
    }
};
// @lc code=end

