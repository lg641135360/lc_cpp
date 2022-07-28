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
class Solution
{
public:
    //     int findTilt(TreeNode *root)
    //     {
    //         // 从root节点开始递归
    //         if (root)
    //             dfs(root);
    //         return ans;
    //     }

    // private:
    //     int ans = 0;

    //     // 计算给定根节点的子树的坡度
    //     // 后序遍历
    //     int dfs(TreeNode *root)
    //     {
    //         // 后序
    //         int left = root->left ? dfs(root->left) : 0;
    //         int right = root->right ? dfs(root->right) : 0;
    //         ans += abs(left - right);
    //         return left + right + root->val;
    //     }

    // 从root节点开始计算坡度
    int findTilt(TreeNode *root)
    {
        if (root)
            dfs(root);
        return ans;
    }

private:
    int ans = 0;

    // 具体计算坡度
    int dfs(TreeNode *root)
    {
        // base case
        if (!root)
            return 0;
        int left, right;
        if (!root->left)
            left = 0;
        else
            left = dfs(root->left);
        if (!root->right)
            right = 0;
        else
            right = dfs(root->right);
        // 后序计算该树的坡度
        ans += abs(left - right);
        // 返回这个树的坡度
        return left + right + root->val;
    }
};
// @lc code=end
