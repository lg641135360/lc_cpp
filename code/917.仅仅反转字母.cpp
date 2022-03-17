/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution
{
public:
    // 双指针，互相交换
    string reverseOnlyLetters(string s)
    {
        int start = 0, end = s.size() - 1;
        while(start<end)
        {
            // 添加范围判断，不然一直滑动下去
            while(!isEnglishChar(s[start]) && start < end)
                start++;
            while(!isEnglishChar(s[end]) && start < end)
                end--;
            // 现在两个位置都是英语字符，交换之
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
        return s;
    }

    bool isEnglishChar(char ch)
    {
        if ((ch - 'A' >= 0) && ('Z' - ch >= 0))
            return true;
        else if ((ch - 'a' >= 0) && ('z' - ch >= 0))
            return true;
        else
            return false;
    }
};
// @lc code=end
