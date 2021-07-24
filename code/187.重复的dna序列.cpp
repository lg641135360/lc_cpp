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

    // int g_hash_map[1048576] = {0};

    // string change_int_to_DNA(int DNA) {
    //     static const char DNA_CHAR[] ={'A','C','G','T'};
    //     string str;
    //     for(int i=0;i<10;i++) {
    //         str += to_string(DNA_CHAR[DNA&3]);
    //         DNA = DNA >> 2;
    //     }
    //     return str;
    // }

    // vector<string> findRepeatedDnaSequences(string s) { 
    //     vector<string> res;
    //     if(s.size() <10) return res;
    //     for(int i=0;i<1048576;++i) 
    //         g_hash_map[i] = 0;
    //     int char_map[128] = {0};
    //     char_map['A'] = 0;
    //     char_map['C'] = 1;
    //     char_map['G'] = 2;
    //     char_map['T'] = 3;
    //     int key = 0;
    //     for(int i=9;i>=0;i--)
    //         key = (key<<2) + char_map[s[i]];
    //     g_hash_map[key] = 1;
    //     for(int i=0;i<s.size();++i) {
    //         key = key >>2;
    //         key = key | (char_map[s[i]] << 18);
    //         g_hash_map[key] ++;
    //     }
    //     for(int i=0;i<1048576;++i) 
    //         if(g_hash_map[i] > 1)
    //             res.push_back(change_int_to_DNA(i));
    //     return res;
    // } 
};
// @lc code=end

