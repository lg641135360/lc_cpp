/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        TreeNode *root = new TreeNode;
        int max_ = nums[0];
        int maxI = 0;

        // 选取最大值作为根节点
        for (int i = 1; i < nums.size(); i++)
        {
            if (max_ < nums[i])
            {
                max_ = nums[i];
                maxI = i;
            }
        }
        root->val = max_;
        vector<int> left(nums.begin(), nums.begin() + maxI);
        vector<int> right(nums.begin() + maxI + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};
// @lc code=end
