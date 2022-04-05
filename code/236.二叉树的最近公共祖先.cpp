/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
class Solution
{
public:
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    // {
    //     vector<TreeNode *> path;
    //     vector<TreeNode *> node_p_path;
    //     vector<TreeNode *> node_q_path;
    //     int finish = 0;
    //     preorder(root, p, path, node_p_path, finish);
    //     path.clear();
    //     finish = 0;
    //     preorder(root, q, path, node_q_path, finish);
    //     int path_len = 0;
    //     if (node_p_path.size() <= node_q_path.size())
    //         path_len = node_p_path.size();
    //     else
    //         path_len = node_q_path.size();
    //     TreeNode *res = 0;
    //     for (int i = 0; i < path_len; ++i)
    //         if (node_p_path[i] == node_q_path[i])
    //             res = node_p_path[i]; // 最后一个会覆盖前面相等的
    //     return res;
    // }

    // void preorder(TreeNode *node, TreeNode *search, vector<TreeNode *> &path, vector<TreeNode *> &res, int &finish)
    // {
    //     if (!node || finish)
    //         return;
    //     path.push_back(node);
    //     if (node == search)
    //     {
    //         finish = 1;
    //         res = path;
    //     }
    //     preorder(node->left, search, path, res, finish);
    //     preorder(node->right, search, path, res, finish);
    //     path.pop_back();
    // }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == q || root == p || !root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;

        if (!left && right)
            return right;
        else if (left && !right)
            return left;
        else
            return nullptr;
    }
};
// @lc code=end
