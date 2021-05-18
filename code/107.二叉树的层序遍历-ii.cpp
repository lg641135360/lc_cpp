/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currentLevel = q.size();
            res.push_back(vector<int> ());
            for(int i = 1; i <= currentLevel; i++){
                auto node = q.front();
                q.pop();
                res.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return reverseArray(res);
    }

    vector<vector<int>> reverseArray(vector<vector<int>> a){
        return {a.rbegin(),a.rend()};
    }
};
// @lc code=end

