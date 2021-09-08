/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        // 首先应该去除尾部的空格
        s.erase(s.find_last_not_of(" ") + 1);

        int start = s.size()-1;
        int end = s.size()-1;
        for(int i=s.size()-1;i>=0;--i) {
            if(s[i] != ' ')
                start --;
            else break;
        }
        return end-start;
    }
};
// @lc code=end
