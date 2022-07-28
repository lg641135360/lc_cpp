/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int goodNodes(TreeNode *root)
    {
        // 二叉树中节点数目范围是 [1, 10^5] 。
        dfs(root, root->val);
        return ans;
    }

private:
    int ans = 0;
    void dfs(TreeNode *root, int maxValue)
    {
        if (!root)
            return;
        if (root->val >= maxValue)
        {
            ++ans;
            maxValue = root->val;
        }
        dfs(root->left, maxValue);
        dfs(root->right, maxValue);
    }
};
// @lc code=end
