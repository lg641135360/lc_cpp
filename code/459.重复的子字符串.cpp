/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    // "abaababaab"解决不了
    // bool repeatedSubstringPattern(string s) {
    //     int first_index = 0;
    //     int second_index;
    //     int count;

    //     // base case 
    //     if(s.size()==1) return false;

    //     for(second_index=1;second_index<s.size();++second_index) 
    //         if(s[first_index] == s[second_index]) 
    //             break;
    //     count = second_index - first_index;
    //     while(second_index<s.size()) {
    //         if(s[first_index++] == s[second_index++])
    //             continue;
    //         else return false;
    //     }
    //     if(first_index%count == 0)
    //         return true;
    //     else return false;
    // }

    // 双倍字符串解法
    // 当字符串中没循环时，从第1个位置开始找s模式串，只能找到第二个s开头
    // 有循环，那必然不是s.size()
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};
// @lc code=end

