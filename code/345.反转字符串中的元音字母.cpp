/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if(!isAIUEO(s[i]))
                ++i;
            else if(!isAIUEO(s[j]))
                j--;
            else swap(s[i++],s[j--]);
        }
        return s;
    }

    bool isAIUEO(char c) {
        char c_lower = tolower(c);
        if(c_lower == 'a' || c_lower == 'i'||c_lower=='u'||c_lower=='e'||c_lower=='o')
            return true;
        else return false;
    }
};
// @lc code=end

