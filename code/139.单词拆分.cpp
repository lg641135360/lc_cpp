/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    //     bool wordBreak(string s, vector<string> &wordDict)
    //     {
    //         unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    //         return backtracking(s, wordSet, 0);
    //     }
    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    //     vector<bool> memory(s.size(), 1); // -1 表示初始化状态
    //     return backtracking(s, wordSet, memory, 0);
    // }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (wordset.find(word) != wordset.end() && dp[j])
                    dp[i] = true;
            }
        return dp[s.size()];
    }

private:
    //     bool backtracking(const string &s, const unordered_set<string> &wordSet, int startIndex)
    //     {
    //         if (startIndex >= s.size())
    //         {
    //             return true;
    //         }
    //         for (int i = startIndex; i < s.size(); i++)
    //         {
    //             string word = s.substr(startIndex, i - startIndex + 1);
    //             if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i + 1))
    //             {
    //                 return true;
    //             }
    //         }
    //         return false;
    //     }

    bool backtracking(const string &s,
                      const unordered_set<string> &wordSet,
                      vector<bool> &memory,
                      int startIndex)
    {
        if (startIndex >= s.size())
        {
            return true;
        }
        // 如果memory[startIndex]不是初始值了，直接使用memory[startIndex]的结果
        if (!memory[startIndex])
            return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++)
        {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, memory, i + 1))
            {
                return true;
            }
        }
        memory[startIndex] = false; // 记录以startIndex开始的子串是不可以被拆分的
        return false;
    }
};
// @lc code=end
