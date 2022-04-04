/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
class Solution
{
public:
    // 一次通过，哈哈哈哈
    // TreeNode* invertTree(TreeNode* root) {
    //     if(!root) return NULL;
    //     TreeNode* tmp;
    //     tmp  = root->left;
    //     root->left = root->right;
    //     root->right = tmp;
    //     // 在递归之前处理好本节点的事情
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     return root;
    // }

    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end
