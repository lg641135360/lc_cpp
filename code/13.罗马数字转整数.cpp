/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        // 首先获取字符串的长度，要转换的数字长度
        int len = s.size();

        int res = 0;
        // 先考虑最简单的，吧所有数字转换后加起来
        // for(int i=0;i<len;++i) {
        //     res += charToInt(s[i]);
        // }

        s+='z';  // 减少额外的判断

        // 现在考虑左边比右边小的，算结果时，加（右-左）
        for(int i=0;i<s.size()-1;) {
            if(charToInt(s[i]) < charToInt(s[i+1])) {
                res+= (charToInt(s[i+1]) - charToInt(s[i]));
                i += 2;
            }
            else res += charToInt(s[i++]);
        }


        return res;
    }

    int charToInt(char c) {
        int res;
        switch(c) {
            case 'I':
                res=1;
                break;
            case 'V':
                res=5;
                break;
            case 'X':
                res=10;
                break;
            case 'L':
                res=50;
                break;
            case 'C':
                res=100;
                break;
            case 'D':
                res=500;
                break;
            case 'M':
                res=1000;
                break;
            default:  // 方便for循环，不用做额外处理
                res=0;
        }
        return res;
    }
};
// @lc code=end

