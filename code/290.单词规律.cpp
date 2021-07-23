/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string,char> word_map;
        char used[128] = {0};
        string word;    // 临时拆分出的单词
        int pos = 0;    // 当前指向的pattern字符
        str.push_back(' ');   // 无需特殊处理最后一个单词
        for(int i=0;i<str.size();++i) {
            if(str[i] == ' ') {
                if(pos == pattern.size())
                    return false;
                if(word_map.find(word) == word_map.end()) {
                    if(used[pattern[pos]])
                        return false;
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1; 
                }
                else if(word_map[word] != pattern[pos])
                    return false;
                word = "";
                pos++;
            } 
            else word += str[i];                
        }
        if(pos!=pattern.size())
            return false;
        return true;
    }
};
// @lc code=end

