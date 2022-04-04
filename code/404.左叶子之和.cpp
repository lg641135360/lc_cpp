/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    // 这里isLeft默认为false
    // int sumOfLeftLeaves(TreeNode* root, bool isLeft=false) {
    //     if (!root)
    //         return 0;
    //     int res = !root->left && !root->right && isLeft? root->val:0;
    //     return res + sumOfLeftLeaves(root->left,true)
    //                 + sumOfLeftLeaves(root->right,false);
    // }

    int sumOfLeftLeaves(TreeNode *root, bool isLeft = false)
    {
        if (!root)
            return 0;
        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue = sumOfLeftLeaves(root->right);

        int midValue = 0;
        if (root->left && !root->left->left && !root->left->right)
            midValue = root->left->val;
        int sum = midValue + leftValue + rightValue;
        return sum;
    }

    // int sumOfLeftLeaves(TreeNode *root)
    // {
    //     stack<TreeNode *> st;
    //     if (!root)
    //         st.push(root);
    //     int res = 0;
    //     while (!st.empty())
    //     {
    //         TreeNode *node = st.top();
    //         st.pop();
    //         if (node->left && !node->left->left && !node->left->right)
    //             res += node->left->val;
    //         if (node->right)
    //             st.push(node->right);
    //         if (node->left)
    //             st.push(node->left);
    //     }
    //     return res;
    // }
};
// @lc code=end
