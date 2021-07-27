/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        // int second_little = -1;
        dfs(root,s);
        if(s.size() >= 2) {
            s.erase(s.begin());
            return *s.begin();
        }
        else return -1;
    }
    
    void dfs(TreeNode *node,set<int> &s) {
        if(!node) return ;
        s.insert(node->val);
        dfs(node->left,s);
        dfs(node->right,s);
    }
};
// @lc code=end

