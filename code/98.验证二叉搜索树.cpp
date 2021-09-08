/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 根节点比左子树    每个    节点大，比右子树     每个节点 小
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }

    bool checkBST(TreeNode* root, long min, long max){
        if(!root) return true;
        if(min >= root->val) return false;
        if(root->val >= max) return false;
        return checkBST(root->left,min,root->val) 
            && checkBST(root->right,root->val,max);
    }
};
// @lc code=end

