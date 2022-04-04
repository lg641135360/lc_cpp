/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> view;
    //     queue<pair<TreeNode*,int>> q;

    //     if(root)
    //         q.push(make_pair(root,0));

    //     while(!q.empty()) {
    //         TreeNode *node = q.front().first;
    //         int depth = q.front().second;
    //         q.pop();
    //         if(view.size()==depth) // 该层元素都pop掉，该层最后一个元素
    //             view.push_back(node->val);
    //         else
    //             view[depth] = node->val;  // 这里会刷新该层值
    //         if(node->left)
    //             q.push(make_pair(node->left,depth+1));
    //         if(node->right)
    //             q.push(make_pair(node->right,depth+1));
    //     }
    //     return view;
    // }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (i == (size - 1))
                    res.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return res;
    }
};
// @lc code=end
