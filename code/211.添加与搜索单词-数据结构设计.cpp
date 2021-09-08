/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start

#define TRIE_MAX_CHAR_NUM 26
struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode():is_end(false) {
        for(int i=0;i<TRIE_MAX_CHAR_NUM;++i)
            child[i] = 0;
    }
};


class TrieTree{
public:
    TrieTree(){}
    ~TrieTree(){
        for(int i=0;i<_node_vec.size();++i)
            delete _node_vec[i];
    }
    void insert(const char *word) {
        TrieNode *ptr = &_root;
        while(*word) {
            int pos = *word - 'a';
            if(!ptr->child[pos])
                ptr->child[pos] = new_node();
            ptr = ptr->child[pos];
            word++;
        }
        ptr->is_end = true;
    }

    bool search(const char *word){
        TrieNode *ptr = &_root;
        while(*word) {
            int pos = *word - 'a';
            if(!ptr->child[pos])
                return false;
            ptr = ptr->child[pos];
            word++;
        }
        return ptr->is_end;
    }

    bool startsWith(const char *prefix) {
        TrieNode *ptr = &_root;
        while(*prefix) {
            int pos = *prefix - 'a';
            if(!ptr->child[pos])
                return false;
            ptr = ptr->child[pos];
            prefix ++;
        }
        return true;
    }

    

    TrieNode *root(){
        return &_root;
    }

private:
    TrieNode *new_node() {
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    vector<TrieNode *> _node_vec;
    TrieNode _root;
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
    
    void addWord(string word) {
        _trie_tree.insert(word.c_str());
    }
    
    bool search(string word) {
        return search_trie(_trie_tree.root(),word.c_str());
    }

    bool search_trie(TrieNode *node,const char *word) {
        if(*word=='\0')
            return node->is_end;
        if(*word=='.') {
            for(int i=0;i<TRIE_MAX_CHAR_NUM;++i)
                if(node->child[i] && search_trie(node->child[i],word+1))
                    return true;
        }           
        else {
            int pos = *word - 'a';
            if(node->child[pos] && search_trie(node->child[pos],word+1))
                return true;
        }
        return false;
    }

private:
    TrieTree _trie_tree;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

