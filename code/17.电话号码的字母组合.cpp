/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return res;
        backtrack(digits, 0);
        return res;
    }

private:
    vector<string> res;
    string s;
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    void backtrack(const string &digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(s);
            return;
        }
        else
        {
            int digit = digits[index] - '0';
            string letters = letterMap[digit];
            for (int i = 0; i < letters.size(); i++)
            {
                s.push_back(letters[i]);
                backtrack(digits, index + 1);
                s.pop_back();
            }
        }
    }
};
// @lc code=end
