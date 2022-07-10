/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int begin = 0; // 窗口头指针
        int res = 0;
        string word = "";
        int char_map[128] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            char_map[s[i]]++;
            if (char_map[s[i]] == 1)
            { // word中第一次出现字符
                word += s[i];
                if (res < word.size()) // 更新最长子串长度
                    res = word.size();
            }
            else
            { // 出现重复字符 跳过重复字符
                while (char_map[s[i]] > 1)
                {
                    char_map[s[begin]]--;
                    begin++;
                }
                // 重新更新word
                word = "";
                for (int j = begin; j <= i; ++j)
                    word += s[j];
            }
        }
        return res;
    }
};
// @lc code=end
