/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;     // 路径栈和路径值
        int path_value =0;
        preorder(root,path_value,targetSum,path,res);
        return res;
    }

    void preorder(TreeNode* node,int &path_value,int targetSum,vector<int> &path,vector<vector<int>> &res) {
        if(!node) return ;
        path_value += node->val;
        path.push_back(node->val);
        if(!node->left&&!node->right&&path_value == targetSum) 
            res.push_back(path);
        preorder(node->left,path_value,targetSum,path,res);
        preorder(node->right,path_value,targetSum,path,res);
        path_value -= node->val;
        path.pop_back();
    }
};
// @lc code=end

