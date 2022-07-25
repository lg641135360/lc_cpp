/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return ans;
    }

private:
    int ans = INT_MIN;

    int dfs(TreeNode* cur)
    {
        // base case
        if (!cur)
            return 0;
        int l = dfs(cur->left);
        int r = dfs(cur->right);

        ans = max(ans, max(l, 0) + max(r, 0) + cur->val);
        return max(l, max(r, 0)) + cur->val;
    }
};
// @lc code=end
