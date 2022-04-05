/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     inorder(root, res);
    //     return res;
    // }

    // void inorder(TreeNode* root, vector<int>& res){
    //     if (!root)
    //     {
    //         return;
    //     }
    //     inorder(root->left,res);
    //     res.push_back(root->val);
    //     inorder(root->right,res);
    // }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();

                st.pop();

                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
// @lc code=end
