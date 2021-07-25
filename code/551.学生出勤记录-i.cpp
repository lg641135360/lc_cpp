/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        // int char_map[128] = {0};
        int a_count = 0;
        int max_l_count = 0;  // 记录遍历过程中最大的l_count
        int l_count = 0;
        bool consist = false;
        for(int i=0;i<s.size();++i) 
            if(s[i] == 'A')
                a_count ++;
        for(int i=0;i<s.size();++i) {
            if(s[i] != 'L') {
                consist = false;
                l_count = 0;
                max_l_count = max(max_l_count,l_count);
            }
                
            else {
                consist = true;
                l_count ++;
                max_l_count = max(max_l_count,l_count);
            }
        }
        if(a_count <= 1 && max_l_count <= 2)
            return true;
        else return false;
    }
};
// @lc code=end

