/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    // TreeNode *searchBST(TreeNode *root, int v)
    // {
    //     // base case
    //     if (!root)
    //         return NULL;

    //     if (root->val == v)
    //         return root;
    //     else
    //     {
    //         TreeNode *left = searchBST(root->left, v);
    //         TreeNode *right = searchBST(root->right, v);
    //         if (left)
    //             return left;
    //         else if (right)
    //             return right;
    //     }
    //     return nullptr;
    // }

    TreeNode *searchBST(TreeNode *root, int v)
    {
        if (!root || root->val == v)
            return root;
        if (root->val > v)
            return searchBST(root->left, v);
        if (root->val < v)
            return searchBST(root->right, v);
        return nullptr;
    }

    // TreeNode *searchBST(TreeNode *root, int v)
    // {
    //     while (root)
    //     {
    //         if (root->val > v)
    //             root = root->left;
    //         else if (root->val < v)
    //             root = root->right;
    //         else
    //             return root;
    //     }
    //     return nullptr;
    // }
};
// @lc code=end
