/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
// #define TRIE_MAX_CHAR_NUM 26
// struct TrieNode{
//     TrieNode *child[TRIE_MAX_CHAR_NUM];
//     bool is_end;
//     TrieNode():is_end(false) {
//         for(int i=0;i<TRIE_MAX_CHAR_NUM;++i)
//             child[i] = 0;
//     }
// };

// class TrieTree{
// public:
//     TrieTree(){}
//     ~TrieTree(){
//         for(int i=0;i<_node_vec.size();++i)
//             delete _node_vec[i];
//     }
//     void insert(const char *word) {
//         TrieNode *ptr = &_root;
//         while(*word) {
//             int pos = *word-'a';
//             if(!ptr->child[pos]) 
//                 ptr->child[pos] = new_node();
//             ptr = ptr->child[pos];
//             word++;
//         }
//         ptr->is_end = true;
//     }
//     bool search(const char *word) {
//         TrieNode *ptr = &_root;
//         while(*word) {
//             int pos = *word - 'a';
//             if(!ptr->child[pos])
//                 return false;
//             ptr = ptr->child[pos];
//             word++;
//         }
//         return ptr->is_end;
//     }
//     bool startsWith(const char *prefix) {
//         TrieNode *ptr = &_root;
//         while(*prefix) {
//             int pos = *prefix-'a';
//             if(!ptr->child[pos]) 
//                 return false;
//             ptr=ptr->child[pos];
//             prefix++;
//         }
//         return true;
//     }
// private:
//     TrieNode *new_node() {
//         TrieNode *node = new TrieNode();
//         _node_vec.push_back(node);
//         return node;
//     }
//     vector<TreeNode *> _node_vec;
//     TrieNode _root;
// }

class Solution {
public:
//     // 前缀树
//     string longestWord(vector<string>& words) {
//         sort(words.begin(),words.end());
//         map<string,int> words_map;
//         int longest_word = INT_MIN;
//         for(int i=0;i<words.size();++i) {
//             trieTree_.insert(words[i]);
//             words_map[words[i]] = size(words[i]);
//         }
//         for(int i=0;i<words.size();++i) {
//             if(trieTree_.startsWith(words[i])) 
//         }
//     }
// private:
//     TrieTree trieTree_;

    //对字母排序后，第一个单词一定是共有的，后面只需在此基础上添加
    //如果单词只有一个字母，那一定是共有的
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        set<string> set;
        string res = "";
        for(string s:words) 
            // 如果单词只有一个
            if (s.length() == 1 || set.find(s.substr(0, s.length() - 1))!=set.end()) {
                res = s.length() > res.length() ? s : res;
                set.insert(s);
        }
        return res;
    }
};
// @lc code=end

