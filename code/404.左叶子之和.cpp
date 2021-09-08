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
class Solution {
public:
    // 这里isLeft默认为false
    int sumOfLeftLeaves(TreeNode* root, bool isLeft=false) {
        if (!root)
            return 0;
        int res = !root->left && !root->right && isLeft? root->val:0;
        return res + sumOfLeftLeaves(root->left,true)
                    + sumOfLeftLeaves(root->right,false);
    }


};
// @lc code=end

