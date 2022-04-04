/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    // int minDepth(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     int L = minDepth(root->left);
    //     int R = minDepth(root->right);
    //     // 与树的最大深度不同
    //     return L<R&&L||!R ? 1+L : 1+R;
    // }

    // int minDepth(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;
    //     int depth = 0;
    //     queue<TreeNode *> que;
    //     que.push(root);
    //     while (!que.empty())
    //     {
    //         int size = que.size();
    //         depth++;
    //         for (int i = 0; i < size; i++)
    //         {
    //             TreeNode *node = que.front();
    //             que.pop();
    //             if (node->left)
    //                 que.push(node->left);
    //             if (node->right)
    //                 que.push(node->right);
    //             if (!node->left && !node->right)
    //                 return depth;
    //         }
    //     }
    //     return depth;
    // }

    int minDepth(TreeNode *root)
    {
        return getDepth(root);
    }

private:
    int getDepth(TreeNode *node)
    {
        if (!node)
            return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        if (!node->left && node->right)
            return 1 + rightDepth;
        if (node->left && !node->right)
            return 1 + leftDepth;
        int res = 1 + min(leftDepth, rightDepth);
        return res;
    }
};
// @lc code=end
