/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
public:
    // 调库
    // string toLowerCase(string s) {
    //     for(int i=0;i<s.size();++i)
    //         s[i] = tolower(s[i]);
    //     return s;
    // }

    string toLowerCase(string s) {
        for(int i=0;i<s.size();++i) 
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        return s;
    }
};
// @lc code=end

