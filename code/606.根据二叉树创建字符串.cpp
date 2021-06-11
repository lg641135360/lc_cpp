/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //t为空，则直接返回""
    // t不为空，左右为空，返回 t->val
    // t不为空，左边空或者不空，右边为空，返回t->val(t->left->val)
    // t不为空，左右都不为空，返回 t->va(t->left->val)(t->right->val)


    string tree2str(TreeNode* root) {
        if(!root) return "";
        string res = to_string(root->val);
        if(!root->left && !root->right) return res;
        // 不管到底有没有左节点，都是需要加括号的
        res += "(" +tree2str(root->left) +")";
        // 存在右节点才需要加
        if(root->right)
            res += "(" + tree2str(root->right) + ")";
        return res;
    }   
};
// @lc code=end

