/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // int maxDepth(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     int depth = 1;
    //     return depth + max(maxDepth(root->left),maxDepth(root->right));
    // }

    // int max(int a , int b){
    //    return a>=b? a : b;
    // }

    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return depth;
    }
};
// @lc code=end
