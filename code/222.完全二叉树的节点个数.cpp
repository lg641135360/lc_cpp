/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    // public:
    //     int countNodes(TreeNode *root)
    //     {
    //         return getNodesNum(root);
    //     }

    // private:
    //     int getNodesNum(TreeNode *cur)
    //     {
    //         if (!cur)
    //             return 0;
    //         int leftNum = getNodesNum(cur->left);
    //         int rightNum = getNodesNum(cur->right);
    //         int treeNum = leftNum + rightNum + 1;
    //         return treeNum;
    //     }

public:
    // int countNodes(TreeNode *root)
    // {
    //     queue<TreeNode *> que;
    //     if (root)
    //         que.push(root);
    //     int res = 0;
    //     while (!que.empty())
    //     {
    //         int size = que.size();
    //         for (int i = 0; i < size; i++)
    //         {
    //             TreeNode *node = que.front();
    //             que.pop();
    //             res++;
    //             if (node->left)
    //                 que.push(node->left);
    //             if (node->right)
    //                 que.push(node->right);
    //         }
    //     }
    //     return res;
    // }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftHeight = 0, rightHeight = 0;
        while (left)
        {
            left = left->left;
            leftHeight++;
        }
        while (right)
        {
            right = right->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight)
            return (2 << leftHeight) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end
