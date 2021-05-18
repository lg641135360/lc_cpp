// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem297.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string ans = "";
public:

    // 拼接左右两边,左右都序列化好了，拼接左右即可
    string serialize(TreeNode* root) {
        if(!root) return ans+'#';

        string left = serialize(root->left);
        string right = serialize(root->right);
        string tree = to_string(root->val) + ',' + left + ',' + right;
        ans += tree;
        return tree;
    }

    //字符串转列表
    // 使用引用类型，防止浅拷贝
    queue<string> string_to_list(string& data) {
        queue<string> que;
        int i = 0, j = 0;
        while (i < data.size()) {
            while (i < data.size() && data[i] == ',')  ++i;
            int cnt = 0;
            while (i + cnt < data.size() && data[i + cnt] != ',')  ++cnt;
            if (i + cnt <= data.size()) {
                string tmp = data.substr(i,cnt);
                que.push(tmp);
            }
            i = i + cnt;
        }
        return que;
    }

    TreeNode* decode(queue<string> &data){
        if(data.empty()) return NULL;
        string ch = data.front();
        data.pop();
        if(ch == "#") return NULL;
        
        TreeNode* root = new TreeNode(stoi(ch));
        root->left = decode(data);
        root->right=decode(data);
        return root;
       
    }



    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> list = string_to_list(data);
        return decode(list);
     }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

