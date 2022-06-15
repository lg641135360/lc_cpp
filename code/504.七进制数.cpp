/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        bool isMinor = false;
        if (num < 0)
        {
            num = -num;
            isMinor = true;
        }
        else if(num == 0)
            return "0";

        string res = "";
        while (num)
        {
            int tmp = num % 7;
            res += to_string(tmp);
            num /= 7;
        }
        std::reverse(res.begin(), res.end());
        if (isMinor)
            res.insert(res.begin(), '-');
        return res;
    }
};
// @lc code=end
