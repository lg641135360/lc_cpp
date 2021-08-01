/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            nums.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        sort(nums.begin(),nums.end());
        int min_ = INT_MAX;
        for(int i=1;i<nums.size();++i) {
            min_ = min(nums[i]-nums[i-1],min_);
        }
        return min_;
    }
};
// @lc code=end

