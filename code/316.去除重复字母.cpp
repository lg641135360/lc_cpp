/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<char> vec;
        map<char, int> m;
        for (auto c : s)
            m[c]++;

        for (char c : s)
        {
            if (std::count(vec.begin(), vec.end(), c) == 0)
            {
                while (!vec.empty() && c < vec.back() && m[vec.back()] > 0)
                    vec.pop_back();
                vec.push_back(c);
            }
            m[c]--;
        }
        string res = "";
        for (int i = 0; i < vec.size(); i++)
            res += vec[i];
        return res;
    }
};
// @lc code=end
