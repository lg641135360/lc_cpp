/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rebuildTree(ss);
    }

    TreeNode* rebuildTree(stringstream &ss) {
        string tmp;
        ss >> tmp;  // 每次接受一个string，判定' '为终止符号
        if(tmp == "#")
            return nullptr;
        TreeNode *node = new TreeNode(stoi(tmp));
        node->left = rebuildTree(ss);
        node->right = rebuildTree(ss);
        return node;
    }

    // void change_int_to_string(int val,string &str_val) {
    //     string tmp;
    //     while(val) {
    //         tmp += val / 10 - '0';
    //         val /= 10;
    //     }
    //     for(int i=tmp.size()-1;i>=0;--i) 
    //         str_val += tmp[i];
    //     str_val += '#';
    // }

    // void bst_preorder(TreeNode *node,string &data) {
    //     if(!node) return;
    //     string str_val;
    //     change_int_to_string(node->val,str_val);
    //     data += str_val;
    //     bst_preorder(node->left,data);
    //     bst_preorder(node->right,data);
    // }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

