/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    // 枚举长度为10的子串，设置映射，遍历即可
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> word_map;
        vector<string> res;
        for(int i=0;i<s.size();++i) {
            string word = s.substr(i,10);
            if(word_map.find(word) != word_map.end()) 
                word_map[word] ++;
            else word_map[word] = 1;
        } 
        map<string,int>::iterator it;
        for(it = word_map.begin();it!=word_map.end();it++) {
            if(it->second > 1)
                res.push_back(it->first);
        }
        return res;
    }
};
// @lc code=end

