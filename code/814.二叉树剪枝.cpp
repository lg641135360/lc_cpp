/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode *pruneTree(TreeNode *root)
    {
        TreeNode *ans = new TreeNode(-1);
        ans->left = root;
        dfs(ans);
        return ans->left;
    }

private:
    // 返回子树和，左右子树和为0的，去掉
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);

        if(l == 0)
            root->left = nullptr;
        if(r==0)
            root->right = nullptr;
        return l + r + root->val;
    }
};
// @lc code=end
