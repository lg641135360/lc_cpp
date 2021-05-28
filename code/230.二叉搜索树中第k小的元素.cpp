/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        InOrder(root);
        return res[k-1];
    }
private:
    vector<int> res;
    // 使用中序遍历存储整个序列，取得k-1个最小的就是第k小的数字
    vector<int> InOrder(TreeNode* root){
        if(!root) return {};
        InOrder(root->left);
        res.push_back(root->val);
        InOrder(root->right);
        return res;
    }
};
// @lc code=end

