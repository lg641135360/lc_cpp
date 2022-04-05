/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     if (!root)
    //         return res;

    //     queue <TreeNode*> q;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         int currentLevelSize = q.size();
    //         res.push_back(vector<int> ());
    //         for (int i = 1; i <= currentLevelSize; ++i) {
    //             auto node = q.front();
    //             q.pop();
    //             res.back().push_back(node->val);
    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);
    //         }
    //     }
    //     return res;
    // }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        vector<vector<int>> res;
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            // 固定大小，不能用que.size()，因为que的大小是变化的
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end
