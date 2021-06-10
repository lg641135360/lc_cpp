/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode* root) {
        if(root) dfs(root);
        return ans;
    }
private:
    int ans = 0;
    int dfs(TreeNode* root){
        // 递归到最后一层
        int left = root->left ? dfs(root->left) : 0;
        int right = root->right?dfs(root->right) : 0;
        ans += abs(left - right);
        return left + right + root->val;
    }
};
// @lc code=end

